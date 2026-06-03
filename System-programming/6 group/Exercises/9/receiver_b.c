/* Read from queue and print to stdout */

#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "msg.h"

#define MODE    0600

msgbuf msg;

void receiver(int msg_id, const char* filename)
{
    int fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT | O_EXCL | O_SYNC, 0644);
    if (fd == -1) terminate("FILE ERROR!");

    /* Read from MQ and write to filename */
    int length = 0;
    msg.type = 1;
    while ((length = rcv_msg(msg_id, &msg)) > 0)
    {
        if (write(fd, msg.text, length) != length) terminate("Error!");
        else if (length < 0) printf("data read error!");
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    /* Open the message queue */
    int msg_id = msgget(MSG_KEY, IPC_CREAT | IPC_EXCL | MODE);
    if (msg_id == -1) terminate(ERRMSGGET);

    receiver(msg_id, argv[1]);

    /* Delete the message queue */
    if (msgctl(msg_id, IPC_RMID, NULL) == -1) terminate(ERRMSGCTL);

    return 0;
}