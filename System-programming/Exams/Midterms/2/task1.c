#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cnt;

void func1(int signum)
{
    printf("PPID = %d\n", getppid());
    exit(0);
}

void func2(int signum)
{
    printf("Cnt = %d\n", cnt);
    exit(1);
}

int main(void)
{
    signal(SIGINT, SIG_IGN);

    cnt = 0;
    signal(SIGUSR1, &func1);
    signal(SIGALRM, &func2);

    alarm(10);

    while (1) { cnt++; }

    return 0;
}