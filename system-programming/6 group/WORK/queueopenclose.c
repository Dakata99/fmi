#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main() {

  int msgid;
  struct msqid_ds msg_str;

  if ((msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0644)) == -1) {
    perror("msgget");
    exit(1);
  }

  if ((msgctl(msgid, IPC_STAT, &msg_str)) == -1) {
    perror("msgctl:stat");
    exit(2);
  }

  printf("Owner\t%u\n", msg_str.msg_perm.uid);
  printf("Group\t%u\n", msg_str.msg_perm.gid);
  printf("Creator\t%u\n", msg_str.msg_perm.cuid);
  printf("Perm\t%o\n", msg_str.msg_perm.mode);

  msg_str.msg_perm.uid = 0;    /* root */
  msg_str.msg_perm.mode = 0664;

  if ((msgctl(msgid, IPC_SET, &msg_str)) == -1) {
    perror("msgctl:set");
    exit(2);
  }

  if ((msgctl(msgid, IPC_RMID, NULL)) == -1) {
    perror("msgctl:rm");
    exit(4);
  }

}
