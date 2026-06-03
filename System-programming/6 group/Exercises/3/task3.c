#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <utime.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments!\n");
        return -1;
    }

    struct utimbuf time;
    utime(argv[1], &time);

    printf("Before:\n\tActime: %ld\n\tModtime: %ld\n", time.actime, time.modtime);

    time.actime -= 3600;
    time.modtime += 60;

    printf("After:\n\tActime: %ld\n\tModtime: %ld\n", time.actime, time.modtime);

    return 0;
}