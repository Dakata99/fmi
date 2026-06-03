#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

/*
Readers-writers problem

Variants:
1) Parent writes without synchronizing with childs, cause they only read (do not change memory) 
2) Parent writes, childs wait for him (starving)
    2.1) both can access the file, cause they only read (do not change memory)
    2.2) one by one read the file

The following solution is implemented (contiguous synchonization)

|--------------------------------------------------------|
| writer (p)     | reader1 (c1)      | reader2 (c2)      |
|----------------|-------------------|-------------------|
| p = 1          | c1 = 0            | c2 = 0            |
| p.wait()       | c1.wait()         | c2.wait()         |
| write to file  | print to stdout   | print to stdout   |
| c1.signal()    | c2.signal()       | p.signal()        |
|--------------------------------------------------------|

*/

#define COUNT        3
#define MAXLINE      1024
#define MODE         0600
#define LENGTH(str)  strlen(str)

#define TEXT1        "Something"
#define TEXT2        " is happening!"

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

int sem_id;

union semun
{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

int sem_init(int semid, int semnum, int semval)
{
    union semun arg;
    arg.val = semval;

    if (semctl(semid, semnum, SETVAL, arg.val) == -1) terminate("semctl error!");
}

int sem_wait(int semid, int semnum)
{
    struct sembuf sem = { semnum, -1, SEM_UNDO };
    if (semop(semid, &sem, 1) == -1) terminate("semop error!");
}

int sem_signal(int semid, int semnum)
{
    struct sembuf sem = { semnum, 1, SEM_UNDO };
    if (semop(semid, &sem, 1) == -1) terminate("semop error!");
}

void cleanup(int signum)
{
    if (semctl(sem_id, 0, IPC_RMID, NULL) == -1) terminate("semctl error!");

    printf("Semaphore with id = %d destroyed...\n", sem_id);

    exit(0);
}

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    sem_id = semget(IPC_PRIVATE, 3, IPC_CREAT | IPC_EXCL | MODE);
    if (sem_id == -1) terminate("semget error!");

    sem_init(sem_id, 0, 1); // parent  = p  = 1
    sem_init(sem_id, 1, 0); // child 1 = c1 = 0
    sem_init(sem_id, 2, 0); // child 2 = c2 = 0

    int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) terminate("open error!");

    pid_t child_1 = fork();
    if (child_1 == -1) terminate("fork error!");
    else if (child_1 == 0) /* child 1 - reader */
    {      
        while (1)
        {
            sem_wait(sem_id, 1);
            
            int fd1 = open(argv[1], O_RDONLY);
            if (fd1 == -1) terminate("open error!");

            char buff;

            while (read(fd1, &buff, sizeof(buff))) printf("%c", buff);

            printf("[CHILD 1] PID = %d\n", getpid());

            close(fd1);

            sem_signal(sem_id, 2);
        }
    }
    else /* parent - writer */
    {
        pid_t child_2 = fork();
        if (child_2 == -1) terminate("fork error!");
        else if (child_2 == 0) /* child 2 - reader */
        {
            while (1)
            {
                sem_wait(sem_id, 2);

                int fd2 = open(argv[1], O_RDONLY);
                if (fd2 == -1) terminate("open error!");

                char buff;

                while (read(fd2, &buff, sizeof(buff))) printf("%c", buff);

                close(fd2);

                printf("[CHILD 2] PID = %d\n", getpid());

                sem_signal(sem_id, 0);
            }
        }
        else /* parent - writer */
        {
            signal(SIGINT, cleanup);
            int sw = 1;

            while (1)
            {
                sem_wait(sem_id, 0);

                sleep(5);

                // Switching text
                if (sw)
                {
                    write(fd, TEXT1, strlen(TEXT1));
                    sw = 0;
                }
                else
                {
                    write(fd, TEXT2, strlen(TEXT2));
                    sw = 1;
                }

                sem_signal(sem_id, 1);
            }

            kill(SIGTERM, child_1);
            kill(SIGTERM, child_2);
        }
    }

    return 0;
}