/* Read from SHM and delete SHM */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

#define SHM_SIZE 1024
#define SHM_MODE 0600

int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    char *shm_adr;

    if (argc != 2) terminate("usage: a.out key");

    /* Open a shared memory segment */
    key = atoi(argv[1]);
    shmid = shmget (key, 0, 0);
    
    if (shmid == -1) terminate("shmget error");

    /* Attach the shared memory segment */
    shm_adr = (char*)shmat (shmid, 0, SHM_RDONLY);
    if (shm_adr == (void *)-1) terminate("shmat error");

    /* Read from SHM and print the string */
    printf("%s\n", shm_adr);

    /* Detach the shared memory segment */
    shmdt(shm_adr);

    /* Destroy SHM */
    if (shmctl(shmid, IPC_RMID, 0) == -1) terminate("shmctl error");
    
    return 0;
}