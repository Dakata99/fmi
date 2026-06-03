/* Create semaphore */

#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define SEM_MODE 0600

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

union semun
{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

int main(int argc, char* argv[])
{
    if (argc != 2) return 1;

    int semid;
    int sem_value;
    union semun arg;
    key_t key;

    /* Create a semaphore set */
    key = atoi(argv[1]);
    semid = semget(key, 1, IPC_CREAT | IPC_EXCL | SEM_MODE);
    if (semid == -1)
    {
        if (errno == EEXIST)
        {
            printf("semget: key %d exists\n", key);
            semid = semget(key, 1, 0);
            if (semid == -1) terminate("semget error!");
            else goto readval;
        }
        else terminate("semget error!");
    }

    /* Initialize semval of semaphore */
    arg.val = 1;
    if ((semctl(semid, 0, SETVAL, arg)) == -1) terminate("semctl error!");

    /* Read semval */
    readval:
    if ((sem_value = semctl(semid, 0, GETVAL, 0)) == -1) terminate("semctl error!");

    printf("semval = %d\n", sem_value);

    semctl(semid, 0, IPC_RMID, NULL);

    return 0;
}