/*
USAGE:
    ./a.out command [parameters] file1 file2 file3

EXAMPLE:
    1) cat -r file1 file2 file3 <-> cat -r input output error
    2) cat -E file1 file2 file3

DESCRIPTION:
    1) -r does not exist for the command cat -> will read file1 and write the error to file3
    2) Will read file1 and write output to file2
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <wait.h>
#include <errno.h>
#include <string.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    if (argc < 5) { printf("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    const char* command = argv[1];
    const char* lfile = argv[argc - 1];
    const char* blfile = argv[argc - 2];
    const char* bblfile = argv[argc - 3];

    int size = argc - 3;
    char* params[size];

    for (int i = 1; i < size; i++)
    {
        int len = strlen(argv[i]) + 1;
        params[i - 1] = malloc(len);
        strcpy(params[i - 1], argv[i]);
        params[i - 1][len - 1] = '\0';
    }

    params[size - 1] = NULL;

    int fd1 = open(bblfile, O_RDONLY),
        fd2 = open(blfile, O_WRONLY | O_TRUNC | O_CREAT, 0644),
        fd3 = open(lfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd1 < 0 || fd2 < 0) terminate("No such file\n");

    pid_t pid = fork();
    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0)
    {
        (void) dup2(fd1, STDIN_FILENO);
        (void) dup2(fd2, STDOUT_FILENO);
        (void) dup2(fd3, STDERR_FILENO);
        (void) close(fd1);
        (void) close(fd2);
        (void) close(fd3);

        printf("Executing command (pid = %d)...\n", getpid());
        execvp(command, params);

        if (errno != 0) terminate("");

        for (int i = 0; i < size; i++) free(params[i]);
    }
    
    int status;
    pid_t child = wait(&status);
    printf("Command (pid = %d) finished with status: %d\n", child, status);

    close(fd1);
    close(fd2);

    return 0;
}