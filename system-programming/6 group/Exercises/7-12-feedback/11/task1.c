#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

#include "sem.h"

#define NSEMS 1

int main(void)
{
    // Create semaphore
    int sem_id = semget(IPC_PRIVATE, NSEMS, 0600 | IPC_CREAT | IPC_EXCL);
    if (sem_id == -1) terminate(ERRSEMGET);

    // Set value of semaphore
    semun sem;
    sem.val = 1;

    if (semctl(sem_id, 0, SETVAL, sem.val) == -1) terminate(ERRSEMCTL);   /* последния параметър трябва да е sem */

    // Get value of semaphore
    int sem_value = semctl(sem_id, 0, GETVAL, 0);
    if (sem_value == -1) terminate(ERRSEMCTL);

    printf("After: %d\n", sem_value);

    // Delete semaphore
    if (semctl(sem_id, 1, IPC_RMID, 0) == -1) terminate(ERRSEMCTL);

    return 0;
}