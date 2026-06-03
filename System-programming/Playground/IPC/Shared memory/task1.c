/* Create Shared Memory */

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
    struct shmid_ds shm_buf;
    int shm_size;

    if (argc != 2) terminate("usage: a.out key");

    /* Create a shared memory segment */
    key = atoi(argv[1]);
    shmid = shmget (key, SHM_SIZE, IPC_CREAT | IPC_EXCL | SHM_MODE);
    if (shmid == -1) terminate("shmget error");

    /* Attach the shared memory segment */
    shm_adr = (char*)shmat (shmid, 0, 0);
    if (shm_adr == (void *)-1) terminate("shmat error");

    /* Determine the size of shared memory segment */
    if (shmctl(shmid, IPC_STAT, &shm_buf) == -1) terminate("shmctl error");
    
    shm_size = shm_buf.shm_segsz;
    printf ("SHM attached at address: %p\nSegment size: %d\n", shm_adr, shm_size);

    /* Write a string to the shared memory segment */
    sprintf (shm_adr, "Hello World");

    /* Detach the shared memory segment */
    shmdt (shm_adr);
    
    return 0;
}