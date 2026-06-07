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
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        return -1;
    }

    int status = chdir(argv[1]);
    if (status < 0) terminate("Could not change directory!\n");

    printf("Current directory: %s\n", getcwd(NULL, 0));

    return 0;
}