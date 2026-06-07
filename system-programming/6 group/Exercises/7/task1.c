#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../syshdr.h"

#define SYSTEM 1

void terminate(char* err, int type)
{
    if (type == SYSTEM) perror(err);
    else printf("%s", err);

    exit(EXIT_FAILURE);
}

int main(void)
{
    int fds[2];

    if (pipe(fds) == -1) err_sys_exit("PIPE ERROR!\n"); //terminate("PIPE ERROR!\n", 1);

    close(fds[0]);

    char* msg = "Hello\n";

    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) terminate("SIGNAL ERROR!\n", 1);

    (void) write(fds[1], msg, sizeof(msg));

    close(fds[1]);

    (void) write(STDOUT_FILENO, msg, sizeof(msg));

    return 0;
}