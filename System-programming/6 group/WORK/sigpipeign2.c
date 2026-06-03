#include <stdio.h>
#include <signal.h>

int main() {

  int fd[2];

  struct sigaction sa;
  sa.sa_handler = SIG_IGN;
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
