//shmem3.c 19.12.2022


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SIZE 100

int main() {

  int shmid;
  int *number;
  int pid;

  if ((shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0644)) == -1) {
    perror("shmget");
    exit(1);
  }

  if ((number = shmat(shmid, NULL, 0)) == (void *) -1) {
    perror("shmat");
    exit(2);
  }

  *number = 0;


  if (fork() > 0) {
    pid = getpid();
    while((*number)++ < 100) {
      sleep(2);
      printf("%d %d\n", pid, *number);
    }

    if ((shmctl(shmid, IPC_RMID, NULL)) == -1) {
      perror("shmctl:rm");
      exit(4);
    }
  } else {
    pid = getpid();
    while((*number)++ < 100) {
      sleep(3);
      printf("%d %d\n", pid, *number);
    }
  }
  if ((shmdt(number)) == -1) {
    perror("shmdt");
    exit(3);
  }


}
