/*
Да се напише програма на С, която получава три параметъра - имена на файлове. Стартира командата
tail -21 с аргумент първия подаден файл, като пренасочва стандартния й изход във втория, а изхода
й за грешки - в третия. Накрая извежда кода й на завършване на екрана.
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    if (argc < 4) return -1;

    int out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644),
        err = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (out == -1 || err == -1) return -1;

    pid_t pid = fork();
    if (pid == -1) return -1;
    else if (pid == 0) // child
    {
        close(STDOUT_FILENO); // close 1
        dup(out); // out = 1

        close(STDERR_FILENO); // close 2
        dup(err); // err = 2

        execlp("tail", "tail", "-21", argv[1], NULL);
    }
    else // parent
    {
        int status;
        wait(&status);

        printf("Command exited with status: %d\n", WEXITSTATUS(status));
    }

    close(out);
    close(err);

    return 0;
}