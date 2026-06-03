#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shm.h"

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    int shm_id = shmget(atoi(argv[1]), 100, IPC_CREAT | IPC_EXCL | 0600);
    if (shm_id == -1) terminate(ERRSHMGET);

    char* msg = (char*) shmat(shm_id, NULL, 0);
    if (msg == (void*) -1) terminate(ERRSHMAT);

    sprintf(msg, "Hello, nigga!");
    /* тук трябва да отделиш паметта */
    return 0;
}