#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAXLINE 1024
#define MODE    0600

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int shmid;
int* var;

void sig_handler(int signum)
{
    printf("Exiting with value %d...\n", *var);

    if (shmctl(shmid, IPC_RMID, NULL) == -1) terminate("shmctl error!");

    exit(0);
}

int main(void)
{
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | IPC_EXCL | MODE);
    if (shmid == -1) terminate("shmget error!");

    var = (int*) shmat(shmid, 0, 0);
    if (var == (void*) -1) terminate("shmat error!");

    *var = 0;

    pid_t pid = fork();
    if (pid == -1) terminate("fork error!");
    else if (pid == 0) /* child */
    {
        signal(SIGALRM, sig_handler);

        alarm(5);

        while (1) (*var)++; /* if sleep is added then both proccess return 0 value */
    }
    else /* parent */
    {
        signal(SIGALRM, sig_handler);

        alarm(5);

        while (1) (*var)--; /* if sleep is added then both proccess return 0 value */
    }

    return 0;
}