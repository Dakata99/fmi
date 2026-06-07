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

    int size = argc;
    char* args[size];

    for (int i = 1; i < argc; i++)
    {
        int len = strlen(argv[i]) + 1;
        args[i - 1] = malloc(len);
        strcpy(args[i - 1], argv[i]);
        args[i - 1][len - 1] = '\0';
    }

    args[size - 1] = NULL;

    pid_t pid = fork();
    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        printf("Executing command (pid = %d)...\n", getpid());
        
        execvp(argv[1], args);
        
        if (errno != 0) terminate("");    

        for (int i = 0; i < size; i++) free(args[i]);
    }
    //else // parent -> can be skipped
    //{
        int status;
        pid_t child = wait(&status);
        printf("Command (pid = %d) finished with status: %d\n", child, status);
    //}

    return 0;
}