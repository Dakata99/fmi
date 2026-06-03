#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/sem.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;
    
    key_t key = atoi(argv[1]);

    int semid = semget(key, 1, 0600 | IPC_CREAT);

    if (semid == -1) terminate();

    printf("Semid = %d\nKey = %d\n", semid, key);

    return 0;
}