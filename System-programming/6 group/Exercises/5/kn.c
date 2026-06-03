#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    int fdi, fdio, nb1, nb2;
    char buff[15] ;	
	fdi = open("abc", O_RDONLY); // opens file, needs a check
    fdio = open("abc", O_RDWR); // opens file, needs a check

    nb1 = read(fdi, buff, 6); // buff = Let’s | nb1 = 6
    write (1, buff, nb1); // output: Lets's

    lseek(fdi, 3, SEEK_CUR); // move 3 bytes
    nb1 = read(fdi, buff, 6); // buff = change, nb1 = 6
    write (1, buff, nb1); // output: change

    lseek(fdio, -18, SEEK_END); // move 18 bytes back from EOF
    write(fdio, "tra", 3); // Let’s go trachange the world!

    write(fdio, "vel", 3); // Let’s go travelchange the world!
    nb2 = read(fdio, buff, 5); // buff = chang, nb2 = 5
    write(1, buff, nb2); // output: chang
    write(1, "time", 4); // output: time

    lseek(fdi, -2, SEEK_END); // move 2 bytes back from EOF
    nb2 = read(fdi, buff, 2); // buff = d!, nb2 = 2
    write(1, buff, nb2); // output: d!

    return 0;
}