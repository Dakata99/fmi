#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>

#include "shm.h"

int main(void)
{
    // Create SHM
    int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0600);
    if (shm_id == -1) terminate(ERRSHMGET);

    // Attach SHM
    int* res = (int*) shmat(shm_id, NULL, 0);
    if (res == (void*) -1) terminate(ERRSHMAT);
    
    // Write to SHM
    *res = 0;

    // Read from SHM
    printf("SHM VALUE = %d\n", *res);

    pid_t pid = fork();
    if (pid == -1) terminate("FORK ERROR!");
    else if (pid == 0) // child
    {
        while (*res <= 100)
        {
            printf("[CHILD = %d] SHM VALUE = %d\n", getpid(), (*res)++);
            sleep(2);
        }
        /* трябва да отдели паметта */
    }
    else // parent
    {
        while (*res <= 100)
        {
            printf("[PARENT = %d] SHM VALUE = %d\n", getpid(), *res);
            (*res) *= 2;    /* по условие трябва да увеличаваш. При начална стойност 0 този цикъл е безкраен */
            sleep(4);
        }
        
        // For safety that the SHM will be deleted after the child process has finished
        int status;
        wait(&status);  /* параметъра е излишен но и функцията като цяло е излишна */

        // Detach SHM
        if (shmdt(res) == -1) terminate(ERRSHMDT);

        // Delete SHM
        if(shmctl(shm_id, IPC_RMID, NULL) == -1) terminate(ERRSHMCTL);
    }

    return 0;
}