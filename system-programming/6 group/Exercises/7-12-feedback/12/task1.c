#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) terminate("open error!");

    char buff[3];
    int n = 1;

    pid_t pid = fork();
    if (pid == -1) terminate("fork error!");
    else if (pid == 0) /* child */
    {
        kill(getpid(), SIGSTOP); /* block itself, so the parent writes first */

        while (read(fd, buff, sizeof(buff)) > 0)
        {
            printf("[CHILD] %s\n", buff);

            kill(getppid(), SIGCONT);
            kill(getpid(), SIGSTOP);
        }

        exit(0);
    }
    else /* parent */
    {
        sleep(3);
        while (read(fd, buff, sizeof(buff)) > 0)
        {

            printf("[PARENT] %s\n", buff);
            kill(pid, SIGCONT);
            kill(getpid(), SIGSTOP);
        }

        kill(pid, SIGCONT);

        wait(NULL);
        close(fd);
        exit(0);
    }

    return 0;
}