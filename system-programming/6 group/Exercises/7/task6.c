#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../syshdr.h"

#define SYSTEM 1

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

void func(int sig)
{ 
    printf("CATCHED SIGNAL: \"%s\"\n", strsignal(sig));
}

int main(void)
{
    pid_t pid = fork();
    if (pid == -1) terminate("FORK ERROR!\n", SYSTEM);
    else if (pid == 0) // child
    {
        printf("PID = %d\nPPID = %d\n", getpid(), getppid());
        sleep(4);
        if (signal(SIGTERM, func) == SIG_ERR) terminate("Signal error\n", SYSTEM);
        while (1) {}
    }
    else // parent
    {
        printf("PID = %d\nPPID = %d\n", getpid(), getppid());
        kill(pid, SIGTERM); // terminates the child
        printf("PID = %d\nPPID = %d\n", getpid(), getppid());
        sleep(1);
        if (kill(pid, SIGTERM) == -1) printf("ERROR\n");
        printf("PID = %d\nPPID = %d\n", getpid(), getppid());
    }

    return 0;
}