#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

void print_info(struct shmid_ds* shm_info)
{
    printf("-------------------------------\n");

    struct ipc_perm info = shm_info->shm_perm;

    printf("[KEY] KEY = %d\n"
           "[UID] USER ID = %d\n"
           "[GID] GROUP ID = %d\n"
           "[CUID] CREATOR ID = %d\n"
           "[CGID] GROUP OF CREATOR ID = %d\n"
           "[MODE] MODE = %d\n",
           info.__key, info.uid, info.gid, info.cuid, info.cgid, info.mode);
    printf("-------------------------------\n");
}

int main(int argc, char* argv[])
{
    key_t key = atoi(argv[1]);

    int id = shmget(key, 1, 0);
    if (id == -1) terminate();

    printf("SHM with id = %d deleting...\n", id);

    struct shmid_ds info;

    int status = shmctl(id, IPC_STAT, &info);
    if (status == -1) terminate();

    print_info(&info);

    status = shmctl(id, IPC_RMID, NULL);
    if (status == -1) terminate();

    printf("SHM with id = %d deleted...\n", id);

    return 0;
}