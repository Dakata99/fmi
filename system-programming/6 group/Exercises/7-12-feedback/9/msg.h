#ifndef _MSG_H_
#define _MSG_H_

#define ERRMSGCTL   "MSGCTL ERROR!"
#define ERRMSGGET   "MSGGET ERROR!"
#define ERRMSGSND   "MSGSND ERROR!"
#define ERRMSGRCV   "MSGRVC ERROR!"

#define MSG_KEY     1234
#define MAXLINE     1024

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

typedef struct msgbuf
{
    int len;
    long type;
    char text[MAXLINE];
} msgbuf;

int snd_msg(int msg_id, msgbuf* msg) { return msgsnd(msg_id, (void *) &(msg->type), msg->len, 0); }

int rcv_msg(int msg_id, msgbuf *msg)
{
    int size = msgrcv(msg_id, (void*) &(msg->type), MAXLINE, msg->type, 0);
    msg->len = size;

    return size;
}

#endif