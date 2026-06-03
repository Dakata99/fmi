#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

void terminate(void) { perror(""); exit(EXIT_FAILURE); }

void print_info(struct msqid_ds* msq_info)
{
    printf("-------------------------------\n");

    struct ipc_perm info = msq_info->msg_perm;

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

    int id = msgget(key, 0);
    if (id == -1) terminate();

    printf("MSG DELETING...\n");

    struct msqid_ds info;

    int status = msgctl(id, IPC_STAT, &info);

    printf("msgid = %d\n", id);
    print_info(&info);

    status = msgctl(id, IPC_RMID, NULL);
    if (status == -1) terminate();

    printf("MSG DELETED...\n");

    return 0;
}