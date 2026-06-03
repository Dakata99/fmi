/*
Да се напише програма на С, която получава два параметъра - имена на файлове. Стартира командата
tee, като пренасочва стандартния й вход от първия файл, а стандартния й изход за грешки във втория.
Накрая извежда кода й на завършване на екрана на стандартния изход за грешки, като преди това
го пренасочва във файла tee_errors.
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    if (argc < 3) return -1;

    int status;

    int in = open(argv[1], O_RDONLY), 
        err = open(argv[2], O_WRONLY | O_CREAT, 0644);

    pid_t pid = fork();

    if (pid == -1) return -1;
    else if (pid == 0) // child
    {
        close(STDOUT_FILENO); // close 0
        (void) dup(in); // in = 0

        close(STDERR_FILENO); // close 2
        (void) dup(err); // err = 2

        if (in == -1 || err == -1) return -1;

        execlp("tee", "tee", NULL);
    }
    else // parent
    {
        wait(&status);

        int fd = open("tee_errors", O_WRONLY | O_CREAT | O_TRUNC, 0644); // fd > 2
        if (fd == -1) return -1;

        int saved_stdout = dup(STDOUT_FILENO); // > 3

        close(STDOUT_FILENO); // close 1
        
        (void) dup(fd); // Why is it needed?
        close(fd); // Why is it needed?

        printf("Command exited with status: %d", WEXITSTATUS(status)); // writed to file

        fflush(stdout);

        // restore stdout
        (void) dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdout);

        printf("Command exited with status: %d", WEXITSTATUS(status));
    }

    return 0;
}