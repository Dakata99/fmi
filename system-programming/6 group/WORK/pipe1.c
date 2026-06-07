#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {

  int fd[2];
  pid_t pid;

  if (pipe(fd) == -1) {
    perror("pipe");
    return 1;
  }

  if ((pid = fork()) == -1) {
    perror("fork");
    return 2;
  }
  if (pid == 0) {  /* child */
    /* close useless end */
    close(fd[0]);
    /* redurect */
    close(1);
    dup(fd[1]);
    close(fd[1]);

    execlp(argv[1], argv[1], 0);
    perror(argv[1]);
    return 3;
  } else {  /* parent */
    /* close useless end */
    close(fd[1]);
    /* redurect */
    close(0);
    dup(fd[0]);
    close(fd[0]);

    execlp(argv[2], argv[2], 0);
    perror(argv[2]);
    return 4;
  }

  return 0;
}
