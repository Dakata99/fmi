/*
Example:
    argv[1] = ls, argv[2] = sort, argv[3] = wc
    List curent directory -> sort it -> execute wc
*/

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

int main(int argc, char* argv[]) {

    int fds[2];             // argv[2] <===> argv[3]
    int new_fds[2];         // argv[1]  <===> argv[2]

    pipe(fds);

    pid_t pid = fork();

    if (pid == -1) terminate("Could not fork!\n", 1);
    else if (pid == 0) // Are we in argv[2] command?
    {
        pipe(new_fds);    // If yes, let's make a new pipe!

        pid_t new_pid = fork();
        if (new_pid == -1) terminate("Could not fork!\n", 1);
        else if (new_pid == 0) // Are we in argv[1] command?
        {
            (void) dup2(new_fds[WRITE_END], STDOUT_FILENO);
            
            close(new_fds[READ_END]);
            
            execlp(argv[1], "", NULL);
            
            close(new_fds[WRITE_END]);
            
            exit(1);
        }
        else
        {
            /* If not in argv[1] command, we're in argv[2] command! In the middle!
            Let's set up both input and output properly.
            We have to deal with both pipes */
            (void) dup2(new_fds[READ_END], STDIN_FILENO);
            (void) dup2(fds[WRITE_END], STDOUT_FILENO);
            
            close(new_fds[WRITE_END]);
            
            execlp(argv[2], "", NULL);

            wait(NULL);
            
            close(new_fds[READ_END]);
            
            exit(2);
        }

        exit(3);
    }
    else // If we're not in argv[2] command, we're in argv[3] command
    {
        (void) dup2(fds[READ_END], STDIN_FILENO);

        close(fds[WRITE_END]);
        
        execlp(argv[3], "", NULL);
        
        wait(NULL);
        
        close(fds[READ_END]);
        
        exit(4);
    }

    return 0;   
}