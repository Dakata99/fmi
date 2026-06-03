#include <stdio.h>
#include <signal.h>

void sch(int sig) {
  if (sig == SIGCHLD) {
    printf("Child end\n");
  }
}
int main() {

  signal(SIGCHLD, &sch);

  if (fork() > 0) {
    pause();
  } else {
    sleep(5);
  }

  return 0;
}
