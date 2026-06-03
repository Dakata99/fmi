#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    pid_t pid = fork();
    char* file_name = "abc";

    int fd;

    if (pid < 0) terminate("Could not fork!\n");
    else if (pid == 0) // child
    {
        fd = open(file_name, O_WRONLY);
        if (fd < 0) terminate("Could not open file!\n");

        for (int i = 0; i < 5; i++)
        {
            write(fd, "Child writes\n", sizeof("Child writes\n"));
            write(1, "Child writes\n", sizeof("Child writes\n"));
            sleep(5);
        }
    }
    else // parent
    {
        fd = open(file_name, O_WRONLY);
        if (fd < 0) terminate("Could not open file!\n");

        for (int i = 0; i < 5; i++)
        {
            write(fd, "Parent writes\n", sizeof("Child writes\n"));
            write(1, "Parent writes\n", sizeof("Child writes\n"));
            sleep(10);
        }
    }

    return 0;
}