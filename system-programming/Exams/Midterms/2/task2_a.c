#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define KEY 123
#define MAX 100

typedef struct msgbuf
{
    long mtype;
    char mtext[MAX];
} msgbuf;

int main(void)
{
    int msgid = msgget(KEY, IPC_CREAT | 0644);
    if (msgid == -1) return 1;

    msgbuf msgs[3];

    // receive some messages
    if (msgrcv(msgid, &msgs[0], MAX, 1, 0) == -1) return 2;
    if (msgrcv(msgid, &msgs[1], MAX, 1, 0) == -1) return 3;
    if (msgrcv(msgid, &msgs[2], MAX, 0, 0) == -1) return 4;

    printf("1) MSG[0] = %s\nMSG[1] = %s\nMSG[2] = %s\n", msgs[0].mtext, msgs[1].mtext, msgs[2].mtext);

    msgs[0].mtype = msgs[1].mtype = msgs[2].mtype = 2;
    
    // send them back in reverse order
    if (msgsnd(msgid, &msgs[2], strlen(msgs[2].mtext), 0) == -1) return 5;
    if (msgsnd(msgid, &msgs[1], strlen(msgs[1].mtext), 0) == -1) return 6;
    if (msgsnd(msgid, &msgs[0], strlen(msgs[0].mtext), 0) == -1) return 7;

    sleep(5);

    // if (msgctl(msgid, IPC_RMID, NULL) == -1) return 8;

    return 0;
}