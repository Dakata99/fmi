#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <fcntl.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    pid_t pid = fork();
    int status;

    if (pid == -1) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        status = execlp("ls", "", NULL);
        printf("In child:\n\tCommand = %s, status = %d\n", "ls", status);
    }
    else // parent
    {

        //status = execlp(argv[2], "", NULL);
        printf("In parent:\n\tCommand = %s, status = %d\n", "who", status);
    }

    return 0;
}