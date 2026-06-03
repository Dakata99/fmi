#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE     1024
#define MODE        0600

#define ERRMSGCTL   "MSGCTL ERROR!"
#define ERRMSGGET   "MSGGET ERROR!"
#define ERRMSGSND   "MSGSND ERROR!"
#define ERRMSGRCV   "MSGRVC ERROR!"
#define ERRNOFILE   "Could not open file!"
#define ERRFORK     "Could not fork!"

#define MSGSND      "SENDING MSG"
#define MSGRCV      "RECEIVING MSG"

#define SYSTEM      1
#define USER        0

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

typedef struct
{
    long type;
    char text[MAXLINE];
} msgbuf;

void print(char* msg, char* op)
{
    printf("--------- %s ---------\n"
           "MSG = %s"
           "Length of MSG (counts new line) = %ld\n"
           "-------------------------------\n", op, msg, strlen(msg));
}

void cleanup(int signum)
{
    printf("SIGNALED!\n");
}

void writer(int msg_id)
{
    msgbuf msg;

    char buffer[MAXLINE];
    int status = 1;
    while(status > 0)
    {
        memset(buffer, '\0', sizeof(buffer));

        status = read(1, buffer, sizeof(buffer));

        int length = strlen(buffer);
        strcpy(msg.text, buffer);

        print(buffer, MSGSND);

        if (msgsnd(msg_id, &msg, length + 1, 0) == -1) terminate(ERRMSGSND);
    }
}

void reader(int msg_id)
{
    msgbuf msg;
    int length;

    while ((length = msgrcv(msg_id, &msg, MAXLINE, 0, 0)) != -1)
    {
        print(msg.text, MSGRCV);
        if (length == -1) terminate(ERRMSGRCV);
    }
}

int main(void)
{
    int msg_id = msgget(IPC_PRIVATE, MODE | IPC_CREAT | IPC_EXCL);
    if (msg_id == -1) terminate(ERRMSGGET);

    pid_t pid = fork();

    if (pid == -1) terminate(ERRFORK);
    else if (pid == 0) // child
    {
        signal(SIGINT, cleanup);
        writer(msg_id);
    }
    else // parent
    {
        signal(SIGTERM, cleanup);
        reader(msg_id);
        msgctl(msg_id, IPC_RMID, NULL);
    }

    return 0;
}