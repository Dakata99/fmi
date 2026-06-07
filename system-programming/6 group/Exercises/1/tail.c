#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define DEFAULT 10

int lines(char* file_name)
{
    int fd = open(file_name, O_RDONLY);
    if (fd < 0) return -1;

    char buffer;
    int lines = 0;
    while (read(fd, &buffer, sizeof(buffer))) if (buffer == '\n') lines++;

    return lines;
}

int main(int argc, char* argv[])
{
    if (argc < 2) { perror("Not enough arguments!\n"); exit(EXIT_FAILURE); }
#if 0
    FILE* fd = fopen(argv[1], "r");
    if (fd == NULL) return -1;

    char* line;
    size_t len = 0;
    int total_lines = lines(argv[1]);
    int count = 0;

    while (getline(&line, &len, fd))
        if (count++ == total_lines - DEFAULT) printf("%s", line);

    fclose(fd);
#endif
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { perror("No such file!\n"); exit(EXIT_FAILURE); }

    int count = 1;

    off_t offset = 1;
    size_t size = lseek(fd, 0, SEEK_END) - lseek(fd, 0, SEEK_SET);

    lseek(fd, size - offset++, SEEK_SET); // set at last character

    char buffer;
    int flag1 = 0,
        flag2 = 0;
    while (read(fd, &buffer, sizeof(buffer)))
    {
        //if (flag2) flag2 = 0;
        if (count == DEFAULT + 1) { printf("%c", buffer); continue; }
        //if (buffer == '\n' && count == DEFAULT) flag = 1;
        
        if (buffer == '\n') count++;
        lseek(fd, size - offset++, SEEK_SET);
    }

    return 0;
}