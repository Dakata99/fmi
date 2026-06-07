/* Producer - Consumer with shared memory and semaphores */

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <wait.h>
#include <signal.h>

#define MODE      0600
#define BUFS      20
#define SHM_SIZE (BUFS * 4 + 8)
#define MUTEX     0
#define FULL      1
#define EMPTY     2

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

struct sh_buffer
{
    int rp;
    int wp;
    int array[BUFS];
} *shptr;

union semun
{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

int semid;
int shmid;

/* Signal handler for SIGINT and SIGTERM */
void cleanup(int signum)
{
    if (semctl(semid, 0, IPC_RMID, NULL) == -1) terminate("semctl error(IPC_RMID)!");

    if (shmctl(shmid, IPC_RMID, NULL) == -1) terminate("shmctl error(IPC_RMID)!");

    printf("SHM and semaphores destroyed!");
    exit(0);
}

/* Create and initialuze semaphores */
int sem_init(key_t key, unsigned short* semvals)
{
    int semid;
    union semun arg;

    /* Create semaphores */
    if ((semid = semget(key, 3, IPC_CREAT | IPC_EXCL | MODE)) == -1) return -1;

    /* Initialize the semaphores */
    arg.array = semvals;
    if ((semctl(semid, 0, SETALL, arg.array)) == -1) return -1;

    return semid;
}

/* Create and initialize SHM buffer*/
int shm_init(key_t key)
{
    int shmid;
    int i;

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | IPC_EXCL | MODE)) == -1) terminate("shmget error!");

    shptr = (struct sh_buffer*) shmat(shmid, 0, 0);
    if (shptr == (void*) -1) terminate("shmat error!");

    shptr->rp = 0;
    shptr->wp = 0;
    for (i = 0; i < BUFS; i++) shptr->array[i] = 0;

    return  shmid;
}

/* P operation on semaphore */
void P(int semid, int semnum)
{
    struct sembuf psem = { 0, -1, SEM_UNDO };

    psem.sem_num = semnum;
    if (semop(semid, &psem, 1) == -1) terminate("semop error!");
}

/* V operation on semaphore */
void V(int semid, int semnum)
{
    struct sembuf vsem = { 0, 1, SEM_UNDO };

    vsem.sem_num = semnum;
    if (semop(semid, &vsem, 1) == -1) terminate("semop error!");
}

/* Read item form shared memory buffer */
int removeitem(void)
{
    int item;
    item = shptr->array[shptr->rp];
    shptr->rp = (shptr->rp + 1) % BUFS;

    return item;
}

/* Write item to shared memory buffer */
void enteritem(int item)
{
    shptr->array[shptr->wp] = item;
    shptr->wp = (shptr->wp + 1) % BUFS;
}

int main(int argc, char* argv[])
{
    key_t key;
    int item , i;
    unsigned short semvals[] = { 1, 0, BUFS };

    if (argc < 2) return 1;

    key = atoi(argv[1]);

    /* Create and initialize SHM */
    if ((shmid = shm_init(key)) == -1) terminate("shm_init error!");

    /* Create and initialize semaphores */
    if ((semid = sem_init(key, semvals)) == -1) terminate("sem_init error!");

    signal(SIGINT, cleanup);

    if (fork()) /* parent - consumer */
    {
        signal(SIGTERM, cleanup);
        for (i = 0; ; i++)
        {
            P(semid, FULL);
            P(semid, MUTEX);
            item = removeitem();
            V(semid, MUTEX);
            V(semid, EMPTY);
            item *= 2;
            printf("Consumer: %d\n", item);
        }
    }
    else /* child - producer */
    {
        signal(SIGINT, SIG_DFL);
        for (item = 0; ; item++)
        {
            P(semid, EMPTY);
            P(semid, MUTEX);
            enteritem(item);
            V(semid, MUTEX);
            V(semid, FULL);
            sleep(3); /* for some delay */
        }
    }

    return 0;
}