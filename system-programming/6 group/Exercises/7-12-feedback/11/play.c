#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <signal.h>
#include <string.h>

#include "sem.h"

#define COUNT 2
#define NSEMS 2
#define MODE  0600

int sem_id;
int shmid;

static int *var;

void cleanup(int signum)
{
    printf("\n[SIGNAL] Catched %s\n", strsignal(signum));

    if ((semctl(sem_id, 0, IPC_RMID, NULL)) == -1) terminate(ERRSEMCTL, SYSTEM);
    printf("Semaphore destroyed!\n");

    if ((shmctl(shmid, IPC_RMID, NULL)) == -1) terminate("shmctl error!", SYSTEM);
    printf("SHM destroyed!\n");

    exit(0);
}

int main(void)
{
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | IPC_EXCL | MODE);
    if (shmid == -1) terminate("shmget error!", SYSTEM);

    var = (int *) shmat(shmid, 0, 0);
    (*var) = 1;

    // Create semaphore
    sem_id = semget(IPC_PRIVATE, NSEMS, MODE | IPC_CREAT | IPC_EXCL);
    if (sem_id == -1) terminate(ERRSEMGET, SYSTEM);

    semun arg;

    arg.val = 1;
    (void) semctl(sem_id, 0, SETVAL, arg.val); // set first (parent) semaphore to 1

    arg.val = 0;
    (void) semctl(sem_id, 1, SETVAL, arg.val); // set second (child) semaphore to 0

    signal(SIGINT, cleanup);
    
    pid_t pid = fork();
    if (pid == -1) terminate("FORK ERROR!", SYSTEM);
    else if (pid == 0) // child
    {
        signal(SIGINT, SIG_DFL);

        while (1)
        {
            sem_wait(sem_id, 1);

            (*var)++;
            printf("[CHILD]: %d\n", *var);

            sem_signal(sem_id, 0);
        }
    }
    else // parent
    {
        signal(SIGTERM, cleanup);

        while (1)
        {
            sem_wait(sem_id, 0);

            sleep(3);
            (*var) *= 2;
            printf("[PARENT] var = %d\n", *var);

            sem_signal(sem_id, 1);
        }

        wait(NULL);
        if (semctl(sem_id, 0, IPC_RMID, NULL) == -1) terminate(ERRSEMCTL, SYSTEM);
    }

    return 0;
}