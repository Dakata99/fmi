#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define N 4

int main(int argc, char *argv[]) {

  int fdr, fdw;
  int pid, i, count;
  char buf[N];

  if ((fdr = open(argv[1], O_RDONLY)) == -1) {
    perror(argv[1]);
    exit(1);
  }
  if ((fdw = open(argv[2], O_WRONLY|O_CREAT|O_APPEND, 0755)) == -1) {
    perror(argv[2]);
    exit(1);
  }

  if ((pid = fork()) == 0) {
    i=0;
    while((count = read(fdr, buf, N)) > 0 && i++ < 10) {
      sleep(1);
      write(fdw, buf, count);
    }
  } else {
    while(waitpid(pid, NULL, WNOHANG) == 0) {
      sleep(2);
      write(fdw, "-parent-", 8);
    }
  }
  close(fdw);
  close(fdr);
}
