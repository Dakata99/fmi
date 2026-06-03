#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <string.h>

#define LENGTH(x) strlen(x)

void sig_handler(int signum)
{
    printf("Inside handler function\n");
    exit(0);
}

void func2(void)
{
    signal(SIGALRM, sig_handler); // Register signal handler

    alarm(5);  // Scheduled alarm after 2 seconds

    for(int i = 1; ; i++)
    {
        printf("%d : Inside main function\n", i);
        sleep(1);  // Delay for 1 second
    }
}

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    if (size)
    {
        --size;
        for (size_t n = 0; n < size; n++)
        {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

int main(void)
{
    //printf("PAUSE...\n");

    // kill(getpid(), SIGSTOP);

    // printf("RESUMED...\n");

    // func2();

    // char buff[1024];
    // printf("%s", rand_string(buff, 11));

    printf("LENGTH = %ld\n", LENGTH("asdf"));

    return 0;
}