#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define USER   0
#define SYSTEM 1

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

void func(int sig) { printf("Catched signal: \"%s\"\n", strsignal(sig)); }

int main(void)
{
    pid_t pid = fork();
    if (pid == -1) terminate("Could not fork!\n", SYSTEM);
    else if (pid == 0) // child
    {
        printf("[IN CHILD] Sleeping for 3 secs...\n");
        
        sleep(3);
        kill(getppid(), SIGCHLD);   /* това не е необходимо */
        
        printf("[IN CHILD] Exiting...\n");
    }
    else // parent
    {
        printf("[IN PARENT] Waiting for child to exit...\n");

        if (signal(SIGCHLD, func) == SIG_ERR) terminate("Could not send signal!\n", 1);

        pause();

        printf("[IN PARENT] Child exited...\n"
               "[IN PARENT] Exiting...\n");
    }

    return 0;
}
