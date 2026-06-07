#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

int main(int argc, char* argv[])
{
    key_t key = atoi(argv[1]);

    int id = msgget(key, 0600 | IPC_CREAT);
    if (id == -1) terminate();

    printf("msgid = %d\n", id);

    return 0;
}