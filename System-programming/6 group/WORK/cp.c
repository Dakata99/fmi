#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#define N 1024

int main(int argc, char* argv[]) {
  char buf[N];
  int sf, df, size;

  if ((sf = open(argv[1], O_RDONLY)) == -1) {
    perror(argv[1]);
    exit(1);
  }
  if ((df = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0755)) == -1) {
    perror(argv[2]);
    close(sf);
    exit(2);
  }
  while((size = read(sf, buf, N)) > 0) {
    write(df, buf, size);
  }
  close(df);
  close(sf);

  return 0;
}
