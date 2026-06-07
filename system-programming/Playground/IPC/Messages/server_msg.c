/* Server process with single message queues */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define NOFILE  "Can not open file!"
#define MODE    0660
#define MSG_KEY     1234
#define MAXLINE 1024

typedef struct
{
    int len;
    long type;
    char text[MAXLINE];
} Message;

Message msg;

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int snd_msg(int mid, Message* msg)
{
    return (msgsnd(mid, (void*)&(msg->type), msg->len, 0));
}

int rcv_msg(int mid, Message* msg)
{
    int n = msgrcv(mid, (void*) &(msg->type), MAXLINE, msg->type, 0);
    msg->len = n;

    return n; // -1 - error, 0 - EOF, > 0
}

void server(int mid)
{
    char errmsg[MAXLINE];
    int n, fd;

    /* receive file name from client */
    msg.type = 1;

    if ((n = rcv_msg(mid, &msg)) <= 0)
    {
        msg.type = 2;
        msg.len = 0;
        
        snd_msg(mid, &msg);
        
        printf("server: filename read error!\n");
        exit(EXIT_FAILURE);
    }
    msg.text[n] = '\0';
    msg.type = 2;

    /* open file */
    if ((fd = open(msg.text, O_RDONLY)) < 0)
    {
        sprintf(errmsg, ": can't open: %s\n", strerror(errno));
        strcat(msg.text, errmsg);
        msg.len = strlen(msg.text);
        snd_msg(mid, &msg);
    }
    else /* file is open; read from file and send data to client */
    {
        while ((n = read(fd, msg.text, MAXLINE)) > 0)
        {
            msg.len = n;
            snd_msg(mid, &msg);
        }
        close(fd);
        if (n < 0) terminate("server: data read error!");
    }
    msg.len = 0;
    snd_msg(mid, &msg);
}

int main(void)
{
    int mid = msgget(MSG_KEY, MODE | IPC_CREAT | IPC_EXCL);

    if (mid == -1) terminate("msgget error!\n");

    server(mid);

    return 0;
}