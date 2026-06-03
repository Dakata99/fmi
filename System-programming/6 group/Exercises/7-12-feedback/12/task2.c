#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define COUNT   3
#define MAXLINE 1024
#define MODE    0600
#define STR     "SENDING..."
#define LENGTH  strlen(STR)

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

typedef struct msgbuf
{
    int len;
    int type;
    char text[MAXLINE];
} msgbuf;

int snd_msg(int msgid, msgbuf* msg)
{
    return msgsnd(msgid, (void*) &msg->type, msg->len, 0);
}

int rcv_msg(int msgid, msgbuf* msg)
{
    int n = msgrcv(msgid, (void*) &msg->type, MAXLINE, msg->type, 0);
    msg->len = n;

    return n;
}

int main(int argc, char* argv[])
{
    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | IPC_EXCL | MODE);
    if (msgid == -1) terminate("msgget error!");

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) terminate("open error!");

    char buff[COUNT];

    pid_t pid = fork();
    if (pid == -1) terminate("fork error!");
    else if (pid == 0) /* child */
    {
        msgbuf msg;

        msg.len = LENGTH;
        msg.type = 0;
        strcpy(msg.text, STR);

        while (1)
        {
            /* wait for message to unblock process */
            int n = rcv_msg(msgid, &msg);
            
            /* on error */
            if (n == -1) terminate("msgrcv error!");
            else if (n == 0) exit(0);
            
            /* some delay to see that child writes */
            sleep(1);

            /* read from file and print to stdout */
            if (read(fd, buff, sizeof(buff)) > 0) write(1, buff, sizeof(buff)); /* printf("[CHILD] %s\n", buff); */

            /* send message to other process (parent) to start reading */
            if (snd_msg(msgid, &msg) == -1) terminate("snd_msg error!");
        }
    }
    else /* parent */
    {
        msgbuf msg;
        
        msg.len = LENGTH;
        msg.type = 0;       /* типа трябва да е >0 */
        strcpy(msg.text, STR);

        while (1)
        {
            /* sleep for 3 seconds -> read from file -> print to stdout */
            sleep(3);
            int size = read(fd, buff, sizeof(buff));

            /* size <= 0 means there is EOF or some read error */
            if (size <= 0) break;
            
            write(1, buff, sizeof(buff)); /* printf("[PARENT] %s\n", buff); */

            /* send to other process (child) to start reading */
            if (snd_msg(msgid, &msg) == -1) terminate("snd_msg error!");

            /* wait for message to unblock process */
            int n = rcv_msg(msgid, &msg);
            
            /* on error */
            if (n == -1) terminate("msgrcv error!");
            else if (n == 0) break;
        }

        /* send terminating message for other process (child) */
        msg.len = 0;
        snd_msg(msgid, &msg);

        wait(NULL);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}