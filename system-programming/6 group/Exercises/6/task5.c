#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define WRITE_END 1
#define READ_END 0

void terminate(char* err, int system)
{
    if (system) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
    if (argc < 3) terminate("Not enough arguments!\n", 0);

    int fds[2];
    pipe(fds);

    pid_t pid = fork();
    if (pid == -1) terminate("Could not fork!\n", 1);
    else if (pid == 0) // child
    {
        close(fds[WRITE_END]);

        (void) dup2(fds[READ_END], STDIN_FILENO);
        execlp(argv[2], "", NULL);

        close(fds[READ_END]);
    }
    else // parent
    {
        close(fds[READ_END]);

        (void) dup2(fds[WRITE_END], STDOUT_FILENO);
        execlp(argv[1], "", NULL);

        int status;
        wait(&status);

        if (WIFEXITED(status)) printf("Child exited with status: %d\n", WEXITSTATUS(status));

        close(fds[WRITE_END]);
    }

    return 0;
}