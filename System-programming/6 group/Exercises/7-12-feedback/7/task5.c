#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define SYSTEM 1

int i = 0;

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

void func(int sig)
{
    printf("Catched SIGINT\nReseting counter to 0...\n");
    i = 0;
}

int main(void)
{
    for (; ; i++)
    {
        printf("%d\n", i);
        sleep(1);
        
        __sighandler_t sig = signal(SIGINT, func);
        
        if (sig == SIG_ERR) terminate("SIGNAL ERROR!\n", 1);
        else if (i == 10) kill(getpid(), SIGTERM);
    }

    return 0;
}