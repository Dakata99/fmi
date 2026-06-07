#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define N 1024

int main(int argc, char *argv[]) {
 int fd1;
 char buf[N];
 int n, i, count=0;

 if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
  perror(argv[1]);
  return 1;
 }

 while((n = read(fd1, buf, N)) > 0 && count < 10) {
  for (i = 0; i < n; i++) {
   if (buf[i] == '\n') {
    if (++count >= 10) {
     n = i+1;
    }
   }
  }
  if (write(1, buf, n) == -1) {
   perror("write");
   return 2;
  }
 }

 close(fd1);

 return 0;
}
