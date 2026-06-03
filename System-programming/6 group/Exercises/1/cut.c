#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc < 2) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("No such file!\n"); exit(EXIT_FAILURE); }

    size_t m, n;
    scanf("%ld", &m);
    scanf("%ld", &n);

    if (n < m) exit(EXIT_FAILURE);

    char buffer;
    size_t counter = 1;

    while (read(fd, &buffer, sizeof(buffer)))
    {
        if (buffer == '\n')
        { 
            printf("%c", buffer); 
            counter = 0; 
        }
        else if (counter >= m && counter <= n) printf("%c", buffer);
        counter++;
    }

    close(fd);

    return 0;
}