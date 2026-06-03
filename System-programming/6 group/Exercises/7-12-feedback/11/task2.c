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
#define NSEMS 1

int sem_id;

void cleanup(int signum)
{
    printf("\n[SIGNAL] Catched %s\n", strsignal(signum));

    if ((semctl(sem_id, 0, IPC_RMID, NULL)) == -1) { perror(""); exit(EXIT_FAILURE); }

    printf("Semaphore destroyed!\n");

    exit(0);
}
/* решаваш някаква друга задача, с четене от файл и сигнали */
int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    // Open file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) terminate("FILE ERROR!");

    // Create semaphore
    sem_id = semget(IPC_PRIVATE, NSEMS, 0600 | IPC_CREAT | IPC_EXCL);
    if (sem_id == -1) terminate(ERRSEMGET);

    semun arg;
    arg.val = 1;
    (void) semctl(sem_id, 0, SETVAL, arg.val);

    signal(SIGINT, cleanup);

    char buff[COUNT];
    
    pid_t pid = fork();
    if (pid == -1) terminate("FORK ERROR!");
    else if (pid == 0) // child
    {
        signal(SIGINT, SIG_DFL);

        while (read(fd, buff, COUNT) > 0)
        {
            dec(sem_id);
            printf("%s", buff);
            inc(sem_id);
        }
    }
    else // parent
    {
        signal(SIGTERM, cleanup);

        while (read(fd, buff, COUNT) > 0)
        {
            dec(sem_id);
            sleep(3);
            printf("%s", buff);
            inc(sem_id);
        }

        wait(NULL);
        if (semctl(sem_id, 0, IPC_RMID, NULL) == -1) terminate(ERRSEMCTL);
    }

    return 0;
}