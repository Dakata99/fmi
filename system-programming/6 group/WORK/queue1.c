#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define M 100

int main() {

  int msgid;
  struct msgbuf {
    long mtype;
    char mtext[M];
  } msg;

  if ((msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0644)) == -1) {
    perror("msgget");
    exit(1);
  }

  msg.mtype = 1;
  snprintf(msg.mtext, M, "Hello world!");
  if ((msgsnd(msgid, &msg, 12, 0)) == -1) {
    perror("msgsnd");
    exit(2);
  }

  if ((msgrcv(msgid, &msg, M, 1, 0)) == -1) {
    perror("msgrcv");
    exit(3);
  }
  printf("%s\n", msg.mtext);

  if ((msgctl(msgid, IPC_RMID, NULL)) == -1) {
    perror("msgctl:rm");
    exit(4);
  }

}
