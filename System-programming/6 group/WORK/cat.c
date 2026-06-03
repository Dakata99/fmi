#include<unistd.h>
#define N 1024

int main(int argc, char* argv[]) {
  char buf[N];
  int size;

  while((size = read(0, buf, N)) > 0) {
    write(1, buf, size);
  }

  return 0;
}
