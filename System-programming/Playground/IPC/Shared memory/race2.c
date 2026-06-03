/* Race condition with shared memory - process race2 */

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

int main(void)
{
    int shmid;
    long i;
    int cntrace = 0;

    if((shmid = shmget(SHM_KEY, 0, 0)) == -1 ) terminate("race2: shmget failed");
    
    ptr = (struct shared *)shmat(shmid, 0, SHM_RDONLY);
    
    if (ptr == (void *)-1) terminate("race2: shmat failed");
    
    printf ("Race2: shmid=%d\n", shmid);
    
    for (i = 1; i <= 50000000; i++)
        if (2 * SHARED != SHARED + SHARED) cntrace++;
    
    printf("Race2: cntrace = %d\n", cntrace);

    return 0;
}
