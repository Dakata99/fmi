#ifndef _SEM_H_
#define _SEM_H_

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define ERRSEMCTL   "SEMCTL ERROR!"
#define ERRSEMGET   "SEMGET ERROR!"
#define ERRSEMOP    "SEMOP ERROR!"

#define SEM_KEY     1234
#define MAXLINE     1024

#define NORMAL 0
#define SYSTEM 1

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else if (type == NORMAL) printf("%s\n", err);
    
    exit(EXIT_FAILURE);
}

typedef union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
} semun;

/* Binary semaphore */

/* dec operation on semaphore */
void dec(int semid)
{
    struct sembuf psem = { 0, -1, SEM_UNDO };
    if (semop(semid, &psem, 1) == -1) terminate(ERRSEMOP, SYSTEM);
}

/* inc operation on semaphore */
void inc(int semid)
{
    struct sembuf psem = { 0, 1, SEM_UNDO };
    if (semop(semid, &psem, 1) == -1) terminate(ERRSEMOP, SYSTEM);
}

/* Binary semaphore */

// --------------------------------------------------------------------

/* My implementation of binary semaphore */

/* Decrease value of semaphore with index semnum */
void sem_wait(int semid, int semnum)
{
    struct sembuf sem = { semnum, -1, SEM_UNDO };
    if (semop(semid, &sem, 1) == -1) terminate(ERRSEMOP, SYSTEM);
}

/* Increase value of semaphore with index semnum */
void sem_signal(int semid, int semnum)
{
    struct sembuf sem = { semnum, 1, SEM_UNDO };
    if (semop(semid, &sem, 1) == -1) terminate(ERRSEMOP, SYSTEM);
}

#endif