#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <signal.h>
#include <string.h>

#include "sem.h"

#define COUNT 2
#define NSEMS 2
#define MODE  0600

int sem_id;

void cleanup(int signum)
{
    printf("\n[SIGNAL] Catched %s\n", strsignal(signum));

    if ((semctl(sem_id, 0, IPC_RMID, NULL)) == -1) { perror(""); exit(EXIT_FAILURE); }
    printf("Semaphore destroyed!\n");

    exit(0);
}

void sem_wait(int semid, int semnum)
{
    struct sembuf sem = { semnum, -1, SEM_UNDO };
    if (semop(semid, &sem, 1) == -1) terminate(ERRSEMOP);
}

void sem_signal(int semid, int semnum)
{
    struct sembuf sem = { semnum, 1, SEM_UNDO };
    if (semop(semid, &sem, 1) == -1) terminate(ERRSEMOP);
}

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    // Open file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) terminate("FILE ERROR!");

    // Create semaphore
    sem_id = semget(IPC_PRIVATE, NSEMS, MODE | IPC_CREAT | IPC_EXCL);
    if (sem_id == -1) terminate(ERRSEMGET);

    semun arg;

    arg.val = 1;
    (void) semctl(sem_id, 0, SETVAL, arg.val); // set first (parent) semaphore to 1

    arg.val = 0;
    (void) semctl(sem_id, 1, SETVAL, arg.val); // set second (child) semaphore to 0

    signal(SIGINT, cleanup);

    char buff;
    
    pid_t pid = fork();
    if (pid == -1) terminate("FORK ERROR!");
    else if (pid == 0) // child
    {
        signal(SIGINT, SIG_DFL);
        int n = 1;

        while (n > 0)
        {
            sem_wait(sem_id, 1);
            
            n = read(fd, &buff, sizeof(buff));
            printf("%c", buff);

            sem_signal(sem_id, 0);
        }
    }
    else // parent
    {
        signal(SIGTERM, cleanup);

        while (read(fd, &buff, sizeof(buff)) > 0)
        {
            sem_wait(sem_id, 0);
            
            sleep(3);
            printf("%c", buff);

            sem_signal(sem_id, 1);
        }

        wait(NULL);
        if (semctl(sem_id, 0, IPC_RMID, NULL) == -1) terminate(ERRSEMCTL);
    }

    return 0;
}