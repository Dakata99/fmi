#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    char* end;
    key_t key = strtol(argv[1], &end, 10);

    int id = semget(key, 1, IPC_STAT);    /* IPC_STAT не е флаг за semget() */
    if (id == -1) terminate();

    printf("Deleting semaphore with id = %d...\n", id);

    int status = semctl(id, 1, IPC_RMID);

    if (status == -1) terminate();

    printf("Deleted semaphore with id = %d...\n", id);

    return 0;
}