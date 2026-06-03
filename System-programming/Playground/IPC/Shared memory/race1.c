/* Race condition with shared memory - process race1 */

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
#define SHM_KEY  76
#define SHARED   ptr->race

struct shared
{
    int race;
} *ptr;

int shmid;

/* Signal handler for SIGTERM */
void quit(int sig)
{
    if (shmctl(shmid, IPC_RMID, 0) == -1) terminate("race1: shmctl failed");
    
    printf("Race1 quits\n");
}

int main(void)
{
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | IPC_EXCL | SHM_MODE)) == -1) terminate("race1: shmget failed");
    
    ptr = (struct shared *)shmat(shmid, 0, 0);
    
    if ((ptr == (void *)-1)) terminate("race1: shmat failed");

    printf ("Race1: shmid=%d\n", shmid);

    signal(SIGTERM, quit);

    while (1)
    {
        SHARED = 1;
        SHARED = 0;
    }

    return 0;
}
