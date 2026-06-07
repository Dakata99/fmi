#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

const char* parent_str = "Parent writes\n";
const char* child_str = "Child writes\n";

int main(void)
{
    int fd1 = open("tmp", O_RDONLY),
        fd2 = open("res", O_WRONLY | O_CREAT, 0644);

    if (fd1 < 0 || fd2 < 0) terminate("Could not open file!\n");

    pid_t pid = fork();

    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        for (size_t i = 0; i < 5; i++)
        {
            write(fd2, child_str, sizeof(child_str));
            sleep(2);
        }
    }
    else // parent
    {
        char buff[3];
        while (read(fd1, buff, sizeof(buff)))
        {
            write(fd2, buff, sizeof(buff));
            sleep(1);
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}