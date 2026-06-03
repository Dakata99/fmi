#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void print_info(struct stat* info)
{
    printf ("ID of device containing file: %ld\n"
            "Size: %ld\n", info->st_dev, info->st_size);
    // and so on for other members
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("No enough arguments!\n");
        return -1;
    }

    for (int i = 1; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);

        if (fd < 0) printf("No such file - %s!\n", argv[i]);
        else
        {
            printf("--- File %s ---\n", argv[i]);
            struct stat info;
            fstat(fd, &info);
            print_info(&info);
            close(fd);
        }
    }

    return 0;
}