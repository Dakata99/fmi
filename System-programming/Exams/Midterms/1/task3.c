/*
Напишете програма на С, на която се подава един аргумент - име на потребителско име. Изпълнява
who | grep потребител и изкарва кода на завършване на ковейера.
*/

#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    pid_t pid = fork();
    if (pid == -1) return -1;
    else if (pid == 0)
    {
        int fd[2];
        pipe(fd);

        pid_t new_pid = fork();
        if (new_pid == -1) return -1;
        else if (new_pid == 0) // child or grandson
        {
            (void) dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execlp("who", "who", "", NULL);
        }
        else // parent
        {
            (void) dup2(fd[0], STDIN_FILENO);
            close(fd[1]);
            close(fd[0]);
            execlp("grep", "grep", argv[1], NULL);
        }
    }
    else
    {
        int status;
        wait(&status);
        printf("Command exit code: %d\n", status);
    }

    return 0;
}