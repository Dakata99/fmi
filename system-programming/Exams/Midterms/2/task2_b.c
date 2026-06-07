#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define KEY 123
#define MAX 100

#define MSG1 "TEXT1!"
#define MSG2 "TEXT2!"
#define MSG3 "TEXT3!"

typedef struct msgbuf
{
    long mtype;
    char mtext[MAX];
} msgbuf;

int main(void)
{
    int msgid = msgget(KEY, IPC_CREAT | IPC_EXCL | 0644);
    if (msgid == -1) return 1;

    msgbuf msgs[3];
    msgs[0].mtype = msgs[1].mtype = msgs[2].mtype = 1;

    // some messages
    strcpy(msgs[0].mtext, MSG1);
    strcpy(msgs[1].mtext, MSG2);
    strcpy(msgs[2].mtext, MSG3);

    // send messages for main task (task2_a)
    if (msgsnd(msgid, &msgs[0], strlen(msgs[0].mtext), 0) == -1) return 2;
    if (msgsnd(msgid, &msgs[1], strlen(msgs[1].mtext), 0) == -1) return 3;
    if (msgsnd(msgid, &msgs[2], strlen(msgs[2].mtext), 0) == -1) return 4;

    // receive messages to check if they are correct
    if (msgrcv(msgid, &msgs[0], MAX, 2, 0) == -1) return 5;
    if (msgrcv(msgid, &msgs[1], MAX, 2, 0) == -1) return 6;
    if (msgrcv(msgid, &msgs[2], MAX, 2, 0) == -1) return 7;

    printf("2) MSG[0] = %s\nMSG[1] = %s\nMSG[2] = %s\n", msgs[0].mtext, msgs[1].mtext, msgs[2].mtext);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) return 8;

    return 0;
}