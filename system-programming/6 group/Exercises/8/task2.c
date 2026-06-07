#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#include "../../../sys.h"

#define MODE 0600

void print_info(struct shmid_ds* shm_info)
{
    printf("-------------------------------\n");

    struct ipc_perm info = shm_info->shm_perm;

    printf("[UID] USER ID = %d\n"
           "[GID] GROUP ID = %d\n"
           "[CUID] CREATOR ID = %d\n"
           "[CGID] GROUP OF CREATOR ID = %d\n"
           "[MODE] MODE = %d\n",
           info.uid, info.gid, info.cuid, info.cgid, info.mode);
    printf("-------------------------------\n");
}

int main(void)
{
    key_t key = 123;
    int shmid = shmget(key, 1, MODE | IPC_CREAT);
    
    if (shmid == -1) err_sys_exit("Error creating queue!");
    
    printf("KEY OF SHM = %d\n", key);

    struct shmid_ds info;

    int status = shmctl(shmid, IPC_STAT, &info);
    if (status == -1) err_sys_exit("Error reading queue!");

    print_info(&info);

    info.shm_perm.uid = 1234;
    info.shm_perm.gid = 4321;
    info.shm_perm.cuid = 4656;
    info.shm_perm.cgid = 7989;
    info.shm_perm.mode = 0644;

    status = shmctl(shmid, IPC_SET, &info);
    if (status == -1) err_sys_exit("Error setting queue!");

    print_info(&info);

    status = shmctl(shmid, IPC_RMID, NULL);
    if (status == -1) err_sys_exit("Error destroying queue!");

    return 0;
}