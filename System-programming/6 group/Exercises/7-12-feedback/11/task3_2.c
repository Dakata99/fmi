#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <stdlib.h>

#include "sem.h"

#define NSEMS     2
#define TIME      3
#define COUNT     5

#define MSG       "PROCESS 2!"

int main(int argc, char* argv[])
{
    if (argc < 3) terminate("Usage: ./a.out <key> <file>", NORMAL);

    // Get semaphore id from the key = atoi(argv[1])
    int semid = semget(atoi(argv[1]), 0, 0);
    if (semid == -1) terminate(ERRSEMGET, SYSTEM);

    // Open file argv[2]
    int fd = open(argv[2], O_WRONLY | O_SYNC);
    if (fd == -1) terminate("open error!", SYSTEM);

    // Write to file COUNT times, but synchronize with other process
    int n = 0;
    while (n++ < COUNT)
    {
        sem_wait(semid, 1); // Wait until a signal is received

        // Position at the end of file, sleep for TIME seconds and write MSG to file
        lseek(fd, 0, SEEK_END);
        sleep(TIME);
        write(fd, MSG, sizeof(MSG));

        sem_signal(semid, 0); // Signal for other process to continue
    }

    // if (semctl(semid, 0, IPC_RMID, NULL) == -1) terminate(ERRSEMCTL, SYSTEM);
    
    return 0;
}