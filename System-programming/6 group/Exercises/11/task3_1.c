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
#define MODE      0600
#define FILE_MODE 0644

#define MSG       "PROCESS 1!"

int main(int argc, char* argv[])
{
    if (argc < 3) terminate("Usage: ./a.out <key> <file>", NORMAL);

    // Create semaphore with key = atoi(argv[1])
    int semid = semget(atoi(argv[1]), NSEMS, IPC_CREAT | IPC_CREAT | MODE);
    if (semid == -1) terminate(ERRSEMGET, SYSTEM);

    // Set values for semaphore
    semun arg;
    arg.val = 1;
    (void) semctl(semid, 0, SETVAL, arg.val); // sems[0] = 1

    arg.val = 0;
    (void) semctl(semid, 1, SETVAL, arg.val); // sems[1] = 0

    // Open file argv[2]
    int fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY | O_SYNC, FILE_MODE);
    if (fd == -1) terminate("open error!", SYSTEM);

    // Write to file COUNT times, but synchronize with other process
    int n = 0;
    while (n++ < COUNT)
    {
        sem_wait(semid, 0); // Wait until a signal is received

        // Position at the end of file, sleep for TIME seconds and write MSG to file
        lseek(fd, 0, SEEK_END);
        sleep(TIME);
        write(fd, MSG, sizeof(MSG));

        sem_signal(semid, 1); // Signal for other process to continue
    }

    if (semctl(semid, 0, IPC_RMID, NULL) == -1) terminate(ERRSEMCTL, SYSTEM);
    
    return 0;
}