#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("No enough arguments!\n");
        return -1;
    }

    int org = open(argv[1], O_RDONLY);
    if (org < 0)
    {
        printf("No such file!\n");
        return -1;
    }

    size_t size = floor(lseek(org, 0, SEEK_END) / 2);
    lseek(org, 0, SEEK_SET);

    printf("--- First file descriptor working... ---\n");

    char buffer;
    while (size-- && read(org, &buffer, sizeof(buffer))) printf("%c", buffer);

    int copy = dup(org);
    close(org);

    printf("--- Second file descriptor working... ---\n");

    while (read(copy, &buffer, sizeof(buffer))) printf("%c", buffer);

    close(copy);

    return 0;
}