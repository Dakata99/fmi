#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 3) return -1;

    pid_t pid = fork();
    if (pid == -1) return -1;
    else if (pid == 0) // child
    {
        int status = execlp(argv[1], "", NULL);
        if (status == -1) return -1;
    }
    else
    {
        int status;
        wait(&status);

        if (status) return -1;

        status = execlp(argv[2], "", NULL);
        if (status) return -1;
    }

    return 0;
}