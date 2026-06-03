#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    char* end;
    key_t key = strtol(argv[1], &end, 10);

    int id = msgget(key, 0600 | IPC_CREAT);
    if (id == -1) terminate();

    printf("msgid = %d\n", id);

    return 0;
}