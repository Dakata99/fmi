#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    printf("Parent pid = %d\nChild pid(current) = %d\n", getppid(), getpid());
    execlp("ps", "", NULL);

    return 0;
}