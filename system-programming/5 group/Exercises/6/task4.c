#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    if (argc < 3) return -1;

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) return -1;

    pid_t pid1 = fork(),
          pid2 = fork();

    

    return 0;
}