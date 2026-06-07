#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void terminate(char* err)
{
    perror(err);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Not enough arguments!\n");
        return -1;
    }

    int status = symlink(argv[1], argv[2]);
    if (status < 0) terminate("Could not create symbolic link!\n");

    char buffer[30] = { '\0' };

    status = readlink(argv[2], buffer, sizeof(buffer));
    if (status < 0) terminate("Could not read symbolic link!\n");

    printf("%s\n", buffer);

    return 0;
}