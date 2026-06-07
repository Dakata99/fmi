#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 3) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    int fd1 = open(argv[1], O_RDONLY),
        fd2 = open(argv[2], O_WRONLY | O_CREAT);

    if (fd1 < 0 || fd2 < 0) { perror("Could not open files!\n"); exit(EXIT_FAILURE); }

    char buffer;

    while (read(fd1, &buffer, sizeof(buffer))) write(fd2, &buffer, sizeof(buffer));
    
    close(fd1);
    close(fd2);
    
    return 0;
}