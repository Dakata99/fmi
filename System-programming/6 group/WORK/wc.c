#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define N 1024

int main(int argc, char *argv[]) {
 int fd1;
 char buf[N];
 int c = 0, w = 0, l = 0, in_word = 0, i, n;

 if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
  perror(argv[1]);
  return 1;
 }

 while((n = read(fd1, buf, N)) > 0) {
  c += n;
  for (i = 0; i < n; i++) {
   if (buf[i] == '\n') {
    l++;
   }
   if (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n') {
    in_word = 0;
   } else {
    if (! in_word) {
     w++;
    }
    in_word = 1;
   }
  } /* for */
 } /* while */

 close(fd1);

 printf("%u\t%u\t%u\t%s\n", l, w, c, argv[1]);

 return 0;
}
