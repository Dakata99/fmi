#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT 80

void red(void) { printf("\033[1;31m"); }

void reset(void) { printf("\033[0m"); }

int main(int argc, char* argv[])
{
    if (argc < 3) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    int fd = open(argv[2], O_RDONLY);
    if (fd < 0) { perror("No such file!\n"); exit(EXIT_FAILURE); }

    char line[DEFAULT] = { '\0' };
    char buffer;
    size_t i = 0;

    while (read(fd, &buffer, sizeof(buffer)))
    {
        if (buffer == '\n' && strstr(line, argv[1]))
        {
            i = 0;
            red();
            printf("%s\n", line); // TODO: print the searching string in color
            reset();
            memset(line, '\0', strlen(line));
        }
        else line[i++] = buffer;
    }

    close(fd);

    return 0;
}