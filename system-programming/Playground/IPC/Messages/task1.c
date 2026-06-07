/* Example of message queue */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct msgb
{
    int mtype;
    char mtext[1];
};

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    int msgid;
    struct msgb msg;
    struct msqid_ds info;

    if ((msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0600)) == -1) terminate("msgget error!\n");

    msg.mtype = 1;
    msg.mtext[0] = 'a';

    msgsnd(msgid, &msg, 1, 0);

    if (msgctl(msgid, IPC_STAT, &info) == -1) terminate("msgctl 1 error!\n");

    printf("MQ: %03o\ncbytes: %lu\nqnum: %lu\nqbytes: %lu\n",
            info.msg_perm.mode & 0777, info.__msg_cbytes, info.msg_qnum, info.msg_qbytes);

    system("ipcs -q");

    if (msgctl(msgid, IPC_RMID, NULL) == -1) terminate("msgctl 2 error!\n");

    printf("MQ destroyed\n");
}
