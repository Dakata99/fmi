#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd1 = open("example", O_CREAT, 0777);
    if (fd1 < 0)
    {
        perror("");
        return -1;
    }

    (void) umask(0644);

    int fd2 = open("example2", O_CREAT, 0777);
    if (fd2 < 0)
    {
        perror("");
        return -1;
    }

    close(fd1);
    close(fd2);

    return 0;
}