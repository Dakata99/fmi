#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shm.h"

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    int shm_id = shmget(atoi(argv[1]), 0, 0);
    if (shm_id == -1) terminate(ERRSHMGET);

    char* msg = (char*) shmat(shm_id, NULL, 0);
    if (msg == (void*) -1) terminate(ERRSHMAT);

    printf("SHM VALUE = %s\n", msg);

    if (shmdt(msg) == -1) terminate(ERRSHMDT);

    if (shmctl(shm_id, IPC_RMID, NULL) == -1) terminate(ERRSHMCTL);

    return 0;
}