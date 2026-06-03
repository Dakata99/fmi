#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_int(int sig)
{
    int i, j;

    printf("\nsig_int starting...\n");

    for (i = 0; i < 2000000; i++) j += i * i;

    printf("\nsig_int finished\n");
}

/* Sleep function */
void sig_alrm(int sig) {}

unsigned int mysleep(unsigned int nsec)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return(nsec);
    alarm(nsec); // start the timer
    pause(); // next caught signal wakes up

    return alarm(0); // turn off timer and return unslept seconds
}

int main(void)
{
    unsigned int ret_sl;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        perror("Can not reach SIGING\n");
    
    ret_sl = mysleep(4);

    printf("mysleep returned %u\n", ret_sl);
    return 0;
}