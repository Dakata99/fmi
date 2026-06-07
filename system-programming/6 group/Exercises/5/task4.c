#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <wait.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

const char* parent_str = "Parent writes\n";

int main(void)
{
    int fd1 = open("tmp", O_RDONLY),
        fd2 = open("res", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd1 < 0 || fd2 < 0) terminate("Could not open file!\n");

    pid_t pid = fork();

    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        char buff[3];
        while (read(fd1, buff, sizeof(buff)))
        {
            write(1, buff, sizeof(buff));
            sleep(1);
        }
    }
    else // parent
    {
        int status = 1;

        while (status != 0)
        {
            wait(&status);
            write(1, parent_str, sizeof(parent_str));
            sleep(2);
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}