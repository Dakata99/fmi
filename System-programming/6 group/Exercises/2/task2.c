#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("No enough arguments!\n");
        return -1;
    }

    int org = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if (org < 0)
    {
        printf("No such file!\n"); // or perror
        return -1;
    }

    close(STDOUT_FILENO);
    int copy = dup(org);

    char buffer;

    while ((buffer = getchar()) != EOF) write(STDOUT_FILENO, &buffer, sizeof(buffer));

    close(org);
    close(copy);

    return 0;
}