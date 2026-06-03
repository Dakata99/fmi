#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 4 || strcmp(argv[1], "-s") != 0) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    int fd1 = open(argv[2], O_RDONLY),
        fd2 = open(argv[3], O_RDONLY);

    if (fd1 < 0 || fd2 < 0) { perror("No such files!\n"); exit(EXIT_FAILURE); }

    char buff1, buff2;

    while (read(fd1, &buff1, sizeof(buff1) && read(fd2, &buff2, sizeof(buff2))))
        if (buff1 != buff2) exit(EXIT_FAILURE);
    
    close(fd1);
    close(fd2);

    return 0;
}