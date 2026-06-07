/*
Напишете програма на С, на която реализира wc < file1 > file2. Да се изведа изхода на екрана.
*/

#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 3) return -1;

    int in = open(argv[1], O_RDONLY);
    int out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (in == -1 || out == -1) return -1;

    pid_t pid = fork();
    if (pid == -1) return -1;
    else if (pid == 0)
    {
        (void) dup2(in, STDIN_FILENO);
        (void) dup2(out, STDOUT_FILENO);
        close(in);
        close(out);
        execlp("wc", "wc", NULL);
        execlp("wc", "wc", "", NULL);
    }
    else
    {
        int status;
        wait(&status);
        printf("Command status: %d\n", status);
    }
    return 0;
}