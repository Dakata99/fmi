#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_word(char* line)
{
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ' ' && line[i + 1] != ' ') count++;

    return count;
}

int main(int argc, char* argv[])
{
    if (argc < 2) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("No such file!\n"); exit(EXIT_FAILURE); }

    int lines = 0, 
        words = 0,
        bytes = 0;

    char buffer;
    char* line = malloc(255);
    while (read(fd, &buffer, sizeof(buffer)))
    {
        
        if (isascii(buffer)) bytes++;
        if (buffer == ' ') words++;
        if (buffer == '\n') { lines++; words++; }
    }

    printf("%d %d %d %s\n", lines, words, bytes, argv[1]);

    close(fd);

    return 0;
}