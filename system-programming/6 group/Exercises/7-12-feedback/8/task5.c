#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    char* end;
    key_t key = strtol(argv[1], &end, 10);

    int id = shmget(key, 1, 0600 | IPC_CREAT);
    if (id == -1) terminate();

    printf("SHMID = %d\n", id);

    return 0;
}