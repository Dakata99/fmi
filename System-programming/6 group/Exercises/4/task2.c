#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    printf("Starting(current) = %d\n", getpid());

    pid_t pid = fork();
    if (pid == -1) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        printf("In child:\n");
        printf("\tParent pid = %d\n\tChild pid(current) = %d\n", getppid(), getpid());
    }
 
    int status;
    (void) wait(&status);
    printf("In parent:\n");
    printf("\tParent pid = %d\n\tChild pid = %d, status = %d\n", getppid(), getpid(), WEXITSTATUS(status));

    return 0;
}