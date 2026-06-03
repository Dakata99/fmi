#include <stdio.h>
#include <signal.h>

void sph(int sig) {
  if (sig == SIGPIPE) {
    printf("SigPipe\n");
  }
}

int main() {

  int fd[2];

  struct sigaction sa;
  sa.sa_handler = &sph;
  sigaction(SIGPIPE, &sa, NULL);

  pipe(fd);
  close(fd[0]);
  int count = write(fd[1], "abcd", 4);
  if (count == -1) {
    perror("write");
    return 1;
  }
  printf("%d\n", count);

  return 0;
}
