#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void quit(int signum)
{
    printf("Got signal: %s\n", strsignal(signum));
    exit(0);
}

int main(void)
{
    if (signal(SIGINT, quit) == SIG_ERR) perror("Can not reach SIGINT\n");

    for (int i = 0; i < 1000; i++)
    {
        printf("Wait 3 seconds\n");
        sleep(3);   
        printf("%d\n", i);
    }

    return 0;
}