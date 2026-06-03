/* Print the type of file for each of the command line arguments */

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    struct stat info;
    char* ptr = NULL;

    for (int i = 1; i < argc; i++)
    {
        int status = lstat(argv[i], &info);
        if (status == -1)
        {
            fprintf(stdout, "Error reading information for file: %s\n", argv[i]);
            continue;
        }

        mode_t mode = info.st_mode;

        printf("File %s is ", argv[i]);
        if (S_ISREG(mode)) ptr = "regular";
        else if (S_ISDIR(mode)) ptr = "directory";
        else if (S_ISCHR(mode)) ptr = "character special device file";
        else if (S_ISBLK(mode)) ptr = "block device";
        else if (S_ISFIFO(mode)) ptr = "fifo";
        else if (S_ISLNK(mode)) ptr = "link";
        else if (S_ISSOCK(mode)) ptr = "socket";
        else ptr = "Unknown\n";

        printf("%s\n", ptr);
    }

    return 0;
}