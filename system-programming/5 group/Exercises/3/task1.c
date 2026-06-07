#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int main(void)
{
    int fd1 = open("fff", O_RDONLY | O_CREAT, 0644),
        fd2 = open("fff", O_WRONLY | O_CREAT),
        fd3 = open("fff", O_RDWR | O_CREAT);

    if (fd1 < 0 | fd2 < 0 | fd3 < 0) terminate("Could not open file fff!\n");

// A)
    char* str1 = "Hello world";
    write(fd2, str1, sizeof(str1));

    char buffer1[6];
    read(fd3, buffer1, sizeof(buffer1));
    printf("%s\n", buffer1);

    char buffer2[5];
    read(fd1, buffer2, sizeof(buffer2));
    printf("%s\n", buffer2);

    char* str2 = "chil";
    write(fd3, str2, sizeof(str2));

    char* str3 = "!!!";
    write(fd2, str3, sizeof(str3));

    char buffer3[9];
    read(fd1, buffer3, sizeof(buffer3));
    printf("%s\n", buffer3);

// B)

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}