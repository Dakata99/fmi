#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

  int fd;
  int i;

  if (fork() == 0) {
    if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0755)) == -1) {
      perror(argv[1]);
      exit(1);
    }
    for(i=0; i<10; i++) {
      sleep(3);
      write(fd, "abcde", 5);
    }
    close(fd);
  } else {
    if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0755)) == -1) {
      perror(argv[1]);
      exit(1);
    }
    for(i=0; i<10; i++) {
      sleep(5);
      write(fd, "12345", 5);
    }
    close(fd);
  }
}
