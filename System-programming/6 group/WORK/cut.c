#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define N 1024

int main(int argc, char *argv[]) {
 int fd1;
 char buf[N];
 int m, n, i, s, count=0;

 scanf("%u %u", &m, &n);

 if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
  perror(argv[1]);
  return 1;
 }

 while((s = read(fd1, buf, N)) > 0) {
  for (i = 0; i < s; i++) {
   count++;
   if (buf[i] == '\n') {
    count = 0;
    write(1, "\n", 1);
   }
   if (count >= m && count <= n) {
    if (write(1, &buf[i], 1) == -1) {
     perror("write");
     return 2;
    }
   }
  } /* for */
 } /* while */

 close(fd1);

 return 0;
}
