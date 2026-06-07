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

    int status = link(argv[1], argv[2]);
    if (status < 0) terminate("Could not create link!\n");

    status = unlink(argv[1]);
    if (status < 0) terminate("Could not unlink!\n");

    return 0;
}