#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#include "msg.h"

#define MODE        0600
#define COUNT       3

#define ERRNOFILE   "Could not open file!"

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    int msg_id = msgget(IPC_PRIVATE, MODE | IPC_CREAT | IPC_EXCL);
    if (msg_id == -1) terminate(ERRMSGGET);

    pid_t pid = fork();
    if (pid == 0) // child
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) terminate(ERRNOFILE);

        msgbuf msg;

        // Read from file COUNT bytes and send in MQ
        int n;
        msg.type = 1;
        
        while ((n = read(fd, msg.text, COUNT)) > 0)
        {
            msg.len = n;
            (void) snd_msg(msg_id, &msg);
            sleep(1);
        }

        msg.len = 0;
        (void) snd_msg(msg_id, &msg);   /* не могат да се пращат съобщения с нулева дължина */
    }
    else // parent
    {
        msgbuf msg;
        msg.type = 1;

        // Receive from MQ and print to stdout
        int length = 0;
        while ((length = rcv_msg(msg_id, &msg)) > 0)    /* при нормални условия този цикъл ще е безкраен */
        {
            if (write(1, msg.text, length) != length) terminate("Error!");
            else if (length < 0) printf("data read error!");
        }
        
        if (msgctl(msg_id, IPC_RMID, NULL) == -1) terminate(ERRMSGCTL);
    }   /* по-лесно и правилно е пишещия да изтрие опашката, но след като се увери, че е празна */
        /* да я затвори четящия е по-сложно и опасно */
    return 0;
}