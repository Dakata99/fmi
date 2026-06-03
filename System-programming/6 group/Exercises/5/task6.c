/*
USAGE:
    ./a.out command [parameters] file

EXAMPLE:
    cat -E file <-> cat -r input

DESCRIPTION:
    Will read file
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
    if (argc < 3) { printf("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    const char* command = argv[1];
    const char* file_name = argv[argc - 1];

    int size = argc - 1;
    char* params[size];

    for (int i = 1; i < argc - 1; i++)
    {
        int len = strlen(argv[i]) + 1;
        params[i - 1] = malloc(len);
        strcpy(params[i - 1], argv[i]);
        params[i - 1][len - 1] = '\0';
    }

    params[size - 1] = NULL;

    close(STDOUT_FILENO);
    
    int fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd < 0) terminate("No such file\n");

    pid_t pid = fork();
    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0)
    {
        printf("Executing command (pid = %d)...\n", getpid());
        execvp(command, params);

        if (errno != 0) terminate("");

        for (int i = 0; i < size; i++) free(params[i]);
    }
    
    int status;
    pid_t child = wait(&status);
    printf("Command (pid = %d) finished with status: %d\n", child, status);

    close(fd);

    return 0;
}