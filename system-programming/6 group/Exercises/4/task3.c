#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <fcntl.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments!\n");
        exit(EXIT_FAILURE);
    }

    int status;
    pid_t pid = fork();

    if (pid == -1) terminate("Could not fork!\n");
    else if (pid == 0) (void) execl(argv[1], "", NULL); 

    wait(&status);
    if (WIFEXITED(status)) printf("Status of child was = %d\n", WEXITSTATUS(status));

    return 0;
}