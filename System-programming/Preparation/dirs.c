#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

void terminate(char* err)
{
    perror(err);
    exit(EXIT_FAILURE);
}

int main(void)
{
    DIR *dir_ptr = opendir("..");
    if (dir_ptr == NULL) terminate("Error opening directory!\n");

    struct dirent *dir;

    while ((dir = readdir(dir_ptr)) != NULL)
    {
        printf("Name = %s\t Type = %c\n", dir->d_name, dir->d_type);
    }

    closedir(dir_ptr);

    return 0;
}