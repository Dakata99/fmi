/* Client process with single message queues */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define NOFILE  "Can not open file!"
#define MODE    0660
#define MSG_KEY 1234
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

void client(int mid)
{
    int n;
    printf("Type file name: ");
    fflush(stdout);
    if ((n = read(0, msg.text, MAXLINE)) == -1) terminate("client: filename read error!");

    if (msg.text[n - 1] == '\n') n--;

    if (n == 0) { printf("client: no file name!"); exit(1); }

    msg.text[n] = '\0';
    msg.len = n;
    msg.type = 1;

    snd_msg(mid, &msg); // send file to server

    /* receive date from server */
    msg.type = 2;
    while ((n = rcv_msg(mid, &msg)) > 0)
    {
        /* write reveived data to stdout */
        if (write(1, msg.text, n) != n) terminate("client: date read error!");
        else if (n < 0) terminate("client: data read error!");
    }
}

int main(void)
{
    int mid;

    /* Open the message queue */
    if ((mid = msgget(MSG_KEY, 0)) < 0) terminate("client: cant get message queue!");

    client(mid);

    /* Delete message queue */
    if (msgctl(mid, IPC_RMID, (struct msqid_ds*) 0) < 0) terminate("client: cant RMID message queue");

    return 0;
}