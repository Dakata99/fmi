//cat sem2.c 04.01.2022


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

  int semid;
  union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
  } semunval;
  int val;
  struct sembuf sops[1] = {{0, 0, 0}};

  if ((semid = semget(IPC_PRIVATE, 1, IPC_CREAT|0644)) == -1) {
    perror("semget");
    return 1;
  }
  /* init */
  semunval.val = 1;
  if (semctl(semid, 0, SETVAL, semunval) == -1) {
    perror("semctl:setval");
    return 2;
  }

  if (fork() > 0) {
    sops[0].sem_op = 0;
    semop(semid, sops, 1);
    write(1, "world!\n", 7);

    if (semctl(semid, 0, IPC_RMID) == -1) {
      perror("semctl:rmid");
      return 4;
    }
  } else {
    sleep(2);
    write(1, "Hello ", 6);
    sops[0].sem_op = -1;
    semop(semid, sops, 1);
  }

  return 0;
}
