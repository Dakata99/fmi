#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define N 1024

int main(int argc, char *argv[]) {
 int fd1, fd2;
 char buf1[N], buf2[N];
 int n1, n2, i;

 if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
  perror(argv[1]);
  return 2;
 }
 if ((fd2 = open(argv[2], O_RDONLY)) == -1) {
  perror(argv[2]);
  return 3;
 }

 while((n1 = read(fd1, buf1, N)) > 0 && (n2 = read(fd2, buf2, N)) > 0) {
  if (n1 != n2) {
   return 1;
  }
  for (i = 0; i < n1; i++) {
   if (buf1[i] != buf2[i]) {
    return 1;
   }
  }
 }

 close(fd2);
 close(fd1);

 return 0;
}
