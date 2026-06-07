//shmem1.c 19.12.2021


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SIZE 100

int main() {

  int shmid;
  char *shmem;

  if ((shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0644)) == -1) {
    perror("shmget");
    exit(1);
  }

  if ((shmem = shmat(shmid, NULL, 0)) == (void *) -1) {
    perror("shmat");
    exit(2);
  }

  snprintf(shmem, SIZE, "Hello world!");
  printf("%s\n", shmem);

  if ((shmdt(shmem)) == -1) {
    perror("shmdt");
    exit(3);
  }

  if ((shmctl(shmid, IPC_RMID, NULL)) == -1) {
    perror("shmctl:rm");
    exit(4);
  }

}
