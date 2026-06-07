#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {

 int f, pid, status, fd, i;
 if ((f = fork()) < 0) {
  perror("fork");
  return 1;
 } else if (f > 0) {
  if ((pid = wait(&status)) == -1) {
   perror("wait");
   return 2;
  }
  printf("pid: %d\n", pid); 
  printf("status: %d\n", status); 
 } else {
  /* in */
  if ((fd = open(argv[argc-3], O_RDONLY)) == -1) {
   perror(argv[argc-3]);
   return 3;
  }
  close(0);
  dup(fd);
  close(fd);
  /* out */
  if ((fd = open(argv[argc-2], O_WRONLY|O_CREAT|O_TRUNC, 0755)) == -1) {
   perror(argv[argc-2]);
   return 4;
  }
  close(1);
  dup(fd);
  close(fd);
  /* err */
  if ((fd = open(argv[argc-1], O_WRONLY|O_CREAT|O_TRUNC, 0755)) == -1) {
   perror(argv[argc-1]);
   return 5;
  }
  close(2);
  dup(fd);
  close(fd);
  /* args */
  for(i = 1; i < argc-3; i++) {
   argv[i-1] = argv[i];
  } 
  argv[argc-4] = '\0';
  execvp(argv[0], argv);
  perror("exec");
  return 6;
 }
 return 0;
}
