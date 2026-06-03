// sem1.c 04.01.2022

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

int main(int argc, char *argv[]) {

  int semid;
  union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
  } semunval;
  int val;

  if ((semid = semget(IPC_PRIVATE, 1, IPC_CREAT|0644)) == -1) {
    perror("semget");
    return 1;
  }
  semunval.val = 1;
  if (semctl(semid, 0, SETVAL, semunval) == -1) {
    perror("semctl:setval");
    return 2;
  }
  if ((val = semctl(semid, 0, GETVAL)) == -1) {
    perror("semctl:getval");
    return 3;
  }
  printf("Semaphore value is %d\n", val);
  if (semctl(semid, 0, IPC_RMID) == -1) {
    perror("semctl:rmid");
    return 4;
  }

  return 0;
}
