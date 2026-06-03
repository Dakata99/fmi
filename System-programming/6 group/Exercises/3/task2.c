#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments!\n");
        return -1;
    }

    for (int i = 1; i < argc; i++)
    {
        int status = chmod(argv[i], 0626); // S_IWGRP | (0777 & ~S_IXOTH)
        if (status < 0) printf("Could not change permissions on file %s", argv[i]);
    }

    return 0;
}