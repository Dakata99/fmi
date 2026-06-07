#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define USER   0
#define SYSTEM 1

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

void func(int sig)
{
    /* Can only use terminate("Catched SIGINT!\n", 0); instead the below */
    if (sig == SIGINT) printf("Catched SIGINT!\n");

    exit(0);
}

int main(void)
{
    if (signal(SIGINT, &func) == SIG_ERR) terminate("SIGNAL ERROR!\n", SYSTEM);
    
    int i = 0;
    
    while (++i)
    {
        printf("%d\n", i);
        sleep(1); // to have some delay and not whole output
    }

    return 0;
}