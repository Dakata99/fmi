#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DEFAULT 10

int main(int argc, char* argv[])
{
    if (argc < 2) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    int count = DEFAULT;
    char buffer;

    while (count && read(fd, &buffer, sizeof(buffer)))
    {
        if (buffer == '\n') count--;
        printf("%c", buffer);
    }
    
    close(fd);

    return 0;
}