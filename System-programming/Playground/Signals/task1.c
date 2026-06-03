/*
Example:
    ./a.out &
    [1] pid

    kill -USR1 pid
    received SIGUSR1

    kill -USR2 pid
    revecived SIGUSR2

    kill pid
    [1]+ Terminated a.out
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_usr(int sig)
{
    if (sig == SIGUSR1)
        printf("Received SIGUSR1\n");
    else if (sig == SIGUSR2)
        printf("Received SIGUSR2\n");
    else
        printf("Received signal: %d\n", sig);
}

int main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        perror("Can not catch SIGUSR1\n");
    else if(signal(SIGUSR2, sig_usr) == SIG_ERR)
        perror("Can not catch SIGUSR1\n");

    for ( ; ; )
        pause();

    return 0;
}