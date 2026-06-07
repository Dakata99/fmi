/* Server process with single message queue and many clients */

#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MSG_KEY 1234
#define MSG_MODE 0660
#define MSGMAX 8192
#define MAXLINE 1024

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

typedef struct
{
    int len;
    long type;
    char text[MAXLINE];
} Message;

Message msg;

int msg_id;

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

/* Signal handler for SIGINT and SIGTERM */
void server_quit(int sig)
{
    msgctl(msg_id, IPC_RMID, 0);
    printf("server: is down\n");
}

void server(int id)
{
    char errmsg[MAXLINE];
    int n, fd;
    pid_t pid;

    char *ptr;
    for ( ; ; )
    {
        /* receive pid and file name from client */
        msg.type = 1;
        if ((n = rcv_msg(id, &msg)) <= 0) { terminate("server: filename read error"); continue; }

        msg.text[n] = '\0';
        if ((ptr = (char *)strchr(msg.text, ' ')) == NULL)
        {
            printf("server: error in request: %s", msg.text);

            pid = atol(msg.text);
            msg.type = pid;
            sprintf(errmsg, ": error in request\n");
            strcat(msg.text, errmsg);
            msg.len = strlen(msg.text);
            snd_msg(id, &msg);

            /* send error message to client */
            msg.len = 0;
            snd_msg(id, &msg); /* send END of connection to client */

            continue;
        }

        *ptr++ = 0;
        pid = atol(msg.text);
        msg.type = pid;
        
        if ((fd = open(ptr, O_RDONLY)) == -1)
        {
            sprintf(errmsg, ": can't open: %s\n", strerror(errno));
            strcat(msg.text, errmsg);
            msg.len = strlen(msg.text);
            snd_msg(id, & msg); /* send error message to client */
        }
        else
        {
            while (( n = read(fd, msg.text, MSGMAX)) > 0 )
            {
                msg.len = n;
                snd_msg(id, &msg); /* send text to client */
            }

            if (n < 0) terminate("server: text read error");
            
            close(fd);
        }
        msg.len = 0;
        snd_msg(msg_id, &msg); /* send END of connection to client */
    }
}

int main(void)
{
    /* Create the message queue */
    if ((msg_id = msgget(MSG_KEY, IPC_CREAT|IPC_EXCL|MSG_MODE)) == -1) terminate("MSGGET ERROR!");

    signal(SIGTERM, server_quit);
    signal(SIGINT, server_quit);

    server(msg_id);

    return 0;
}
