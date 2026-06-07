/*
USAGE:
    ./a.out command [parameters] file1 file2

EXAMPLE:
    cat -E file1 file2 <-> cat -r input output

DESCRIPTION:
    Will read file1 and write output to file2
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
    if (argc < 4) { printf("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    const char* command = argv[1];
    const char* last_file = argv[argc - 1];
    const char* before_last_file = argv[argc - 2];

    int size = argc - 2;
    char* params[size];

    for (int i = 1; i < size; i++)
    {
        int len = strlen(argv[i]) + 1;
        params[i - 1] = malloc(len);
        strcpy(params[i - 1], argv[i]);
        params[i - 1][len - 1] = '\0';
    }

    params[size - 1] = NULL;

    int fd1 = open(before_last_file, O_RDONLY);

    int fd2 = open(last_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);

    if (fd1 < 0 || fd2 < 0) terminate("No such file\n");

    pid_t pid = fork();
    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0)
    {
        (void) dup2(fd1, STDIN_FILENO);
        (void) dup2(fd2, STDOUT_FILENO);
        (void) close(fd1);
        (void) close(fd2);

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