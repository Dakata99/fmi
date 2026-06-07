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
    if (argc < 3)
    {
        printf("Not enough arguments!\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    int status;

    if (pid == -1) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        (void) execlp(argv[1], "", NULL);
        printf("In child:\n\tCommand = %s, status = %d\n", argv[1], WEXITSTATUS(status));
    }
    else // parent
    {
        (void) execlp(argv[2], "", NULL);
        printf("In parent:\n\tCommand = %s, status = %d\n", argv[2], WEXITSTATUS(status));
    }

    return 0;
}