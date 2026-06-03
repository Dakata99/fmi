/* Producer - Consumer with message queues */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MODE    0600
#define KEY     1234
#define MAXLINE 1024

struct msgb
{
    long mtype;
    char mtext[MAXLINE];
};

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

static int mid;

/* Signal handler for SIGINT and SIGTERM */
void cleanup(int sig)
{
    if (msgctl(mid, IPC_RMID, NULL) == -1) terminate("msgctl error!\n");

    printf("MQ destroyed!\n");
}

int main(void)
{
    struct msgb msg;
    int i, j, buf;

    if ((mid = msgget(KEY, MODE | IPC_CREAT | IPC_EXCL)) == -1) terminate("msgget error!\n");

    signal(SIGINT, cleanup);

    pid_t pid = fork();
    if (pid == 0) // child - producer
    {
        signal(SIGINT, cleanup);
        for (i = 0; ; i++)
        {
            sleep(1); // for some delay
            msg.mtype = 1;
            *(int *)msg.mtext = i;
            msgsnd(mid, (struct msgbuf *) &msg, sizeof(int), 0);
        }
    }
    else // parent - consumer
    {
        signal(SIGTERM, cleanup);
        for (i = 0; ; i++)
        {
            msgrcv(mid, (struct msgbuf *) &msg, MAXLINE, 1, 0);
            buf = *((int *)msg.mtext);
            buf *= 2;
            printf("Consumer: %d\n", buf);
        }
    }

    return 0;
}
