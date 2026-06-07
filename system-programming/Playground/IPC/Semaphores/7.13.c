/* Mutual exclusion with Dijkstra binary semaphore */

#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <wait.h>

#define SEM_MODE 0600

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

union semun
{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

int fd;

/* Create and initialize a semaphore */
int sem_init(key_t key, int semval)
{
    int semid;
    union semun arg;

    /* Create a semaphore */
    if ((semid = semget(key, 1, IPC_CREAT | IPC_EXCL | SEM_MODE)) == -1) return -1;

    /* Initialize the semaphore
       No need to initialize if semva = -1 */
    if (semval >= 0)
    {
        arg.val = semval;
        if ((semctl(semid, 0, SETVAL, arg.val)) == -1) return -1;
    }
    
    return semid;
}

/* P operation on semaphore */
void P(int semid)
{
    struct sembuf psem = { 0, -1, SEM_UNDO };
    if (semop(semid, &psem, 1) == -1) terminate("P operation failed!");
}

/* V operation on semaphore */
void V(int semid)
{
    struct sembuf vsem = { 0, 1, SEM_UNDO };
    if (semop(semid, &vsem, 1) == -1) terminate("V operation failed!");
}

/* Write to shared file */
int get_shared(void)
{
    int i;
    lseek(fd, 0, SEEK_SET);
    read(fd, &i, sizeof(int));

    return i;
}

/* Read from shared file */
void put_shared(int i)
{
    lseek(fd, 0, SEEK_SET);
    write(fd, &i, sizeof(int));
}

int main(int argc, char* argv[])
{
    if (argc < 4) return 1;

    key_t key;
    int semid;
    int loop;
    int i;
    int buff;

    if ((fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0600)) == -1) terminate("open error!");

    put_shared(0);

    /* Create and initialize a binary semaphore */
    key = atoi(argv[2]);
    if ((semid = sem_init(key, 1)) == -1) terminate("sem_init error!");

    loop = atoi(argv[3]);
    if (fork()) // parent
    {
        for (i = 1; i < loop; i++)
        {
            P(semid);
            buff = get_shared();
            buff += 1;
            put_shared(buff);
            
            V(semid);
        }

        wait(NULL);
        buff = get_shared();
        printf("Shared counter = %d\n", buff);
        semctl(semid, 0, IPC_RMID, NULL); /* delete semaphore */
    }
    else
    {
        for (i = 1; i < loop; i++)
        {
            P(semid);
            buff += get_shared();
            buff += 2;
            put_shared(buff);
            V(semid);
        }
    }

    return 0;
}