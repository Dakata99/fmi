/* Client process with single message queue and many clients */

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

void client(int id)
{
    int n;
    char *ptr;

    snprintf(msg.text, MSGMAX, "%ld ", (long)getpid());
    n = strlen(msg.text);
    ptr = msg.text + n;

    printf("Type file name: ");
    fflush(stdout);

    if ((n = read(0, ptr, MSGMAX - n)) == -1) terminate("client: filename read error");
    
    if ( *(ptr+n-1) =='\n' ) n--;
    
    if (n == 0) terminate("client: no file name");
    
    *(ptr+n) = '\0';
    n = strlen(msg.text);
    msg.len = n;
    msg.type = 1;
    snd_msg(id, &msg); /* send pid and file name to server */

    /* receive text from server and write received text to stdout */
    msg.type = getpid();
    while (( n = rcv_msg(id, &msg)) > 0 )
        if (write(1, msg.text, n) != n) terminate("client: text write error");
    
    if (n < 0) terminate("client: text read error");
}

int main(void)
{
    int msg_id;

    /* Open the message queue */
    if ((msg_id = msgget(MSG_KEY, 0)) == -1) terminate("client: can't get message queue");
    
    client(msg_id);
    
    return 0;
}
