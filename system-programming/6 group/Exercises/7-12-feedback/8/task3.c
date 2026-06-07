#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/sem.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    char* end;
    key_t key = strtol(argv[1], &end, 10);      /* end не е  инициализирана. atoi() също върши работа */

    int semid = semget(key, 1, 0600 | IPC_CREAT);

    if (semid == -1) terminate();

    printf("Semid = %d\nKey = %d\n", semid, key);

    return 0;
}