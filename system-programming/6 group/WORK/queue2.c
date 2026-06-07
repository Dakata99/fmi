#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include <unistd.h>

#define M 100

int main(int argc, char* argv[]) {

  int msgid;
  struct msgbuf {
    long mtype;
    char mtext[M];
  } msg;
  struct msqid_ds msg_str;
  int fd;
  int count;

  if ((msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0644)) == -1) {
    perror("msgget");
    exit(1);
  }

  if (fork() == 0) {
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
      perror("open");
      exit(2);
    }
    msg.mtype = 1;
    while ((count = read(1, msg.mtext, M)) > 0) {
      if ((msgsnd(msgid, &msg, count, 0)) == -1) {
        perror("msgsnd");
        exit(2);
      }
    }
    close(fd);
    do {
      if (msgctl(msgid, IPC_STAT, &msg_str) == -1) {
        perror("msgctl:stat");
        exit(2);
      }
    } while(msg_str.msg_qnum > 0);
    if ((msgctl(msgid, IPC_RMID, NULL)) == -1) {
      perror("msgctl:rm");
      exit(4);
    }
  } else {
    while ((count = msgrcv(msgid, &msg, M, 1, 0)) > 0) {
      write(1, msg.mtext, count);
    }
  }

  return 0;
}
