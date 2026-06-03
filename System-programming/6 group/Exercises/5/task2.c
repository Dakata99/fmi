#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    int fd = open("abc", O_WRONLY | O_APPEND);
    if (fd < 0) terminate("Could not open file!\n");

    pid_t pid = fork();
    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        for (int i = 0; i < 5; i++)
        {
            sleep(4);
            write(fd, "Child writes\n", sizeof("Child writes\n"));
            write(1, "Child writes\n", sizeof("Child writes\n"));
        }
    }
    else // parent
    {
        for (int i = 0; i < 5; i++)
        {
            sleep(6);
            write(fd, "Parent writes\n", sizeof("Child writes\n"));
            write(1, "Parent writes\n", sizeof("Child writes\n"));
        }
    }

    return 0;
}