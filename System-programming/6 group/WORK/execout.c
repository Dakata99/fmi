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
  if ((fd = open(argv[argc-1], O_WRONLY|O_CREAT|O_TRUNC, 0755)) == -1) {
   perror(argv[argc-1]);
   return 3;
  }
  close(1);
  dup(fd);
  close(fd);
  for(i = 1; i < argc-1; i++) {
   argv[i-1] = argv[i];
  } 
  argv[argc-2] = '\0';
  execvp(argv[0], argv);
  perror("exec");
  return 4;
 }
 return 0;
}
