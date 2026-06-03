#include <stdio.h>
#include <signal.h>
#include <limits.h>

unsigned long count = 0;

void sah(int sig) {
  if (sig == SIGALRM) {
    printf("%ul\n", count);
    alarm(1);
  }
}

void sih(int sig) {
  if (sig == SIGINT) {
    count = 0;
  }
}

int main() {

  signal(SIGALRM, &sah);
  signal(SIGINT, &sih);
  alarm(1);
  while(count < ULONG_MAX) {
    count++;
  }

  return 0;
}
