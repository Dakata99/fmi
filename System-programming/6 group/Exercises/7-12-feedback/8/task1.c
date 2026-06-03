#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

#include "../../../sys.h"

#define MODE 0600

void print_info(struct msqid_ds* msq_info)
{
    printf("-------------------------------\n");

    struct ipc_perm info = msq_info->msg_perm;

    printf("[UID] USER ID = %d\n"
           "[GID] GROUP ID = %d\n"
           "[CUID] CREATOR ID = %d\n"
           "[CGID] GROUP OF CREATOR ID = %d\n"
           "[MODE] MODE = %d\n",                  /* ако ползваш %o ще видиш по-добре нещата */
           info.uid, info.gid, info.cuid, info.cgid, info.mode);
    printf("-------------------------------\n");
}

int main(void)
{
    key_t key;
    int msqid = msgget(key, MODE | IPC_CREAT);  /* key не е инициализиран */
    printf("KEY OF QUEUE = %d\n", key);

    if (msqid == -1) err_sys_exit("Error creating queue!");

    struct msqid_ds info;

    int status = msgctl(msqid, IPC_STAT, &info);
    if (status == -1) err_sys_exit("Error reading queue!");

    print_info(&info);

    info.msg_perm.uid = 1234;
    info.msg_perm.gid = 4321;
    info.msg_perm.cuid = 4656;
    info.msg_perm.cgid = 7989;
    info.msg_perm.mode = 0644;

    status = msgctl(msqid, IPC_SET, &info);
    if (status == -1) err_sys_exit("Error setting queue!");

    print_info(&info);

    status = msgctl(msqid, IPC_RMID, NULL);
    if (status == -1) err_sys_exit("Error destroying queue!");

    return 0;
}