#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shm.h"

int main(void)
{
    // Create SHM
    int shm_id = shmget(IPC_PRIVATE, 100, IPC_CREAT | 0600);
    if (shm_id == -1) terminate(ERRSHMGET);

    // Attach SHM
    int* res = (int*) shmat(shm_id, NULL, 0);
    if (res == (void*) -1) terminate(ERRSHMAT);
    
    // Write to SHM
    int var = 919191;
    *res = var;

    // Read from SHM
    printf("SHM VALUE = %d\n", *res);

    // Detach SHM
    if (shmdt(res) == -1) terminate(ERRSHMDT);

    // Delete SHM
    if(shmctl(shm_id, IPC_RMID, NULL) == -1) terminate(ERRSHMCTL);

    return 0;
}