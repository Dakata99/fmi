#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define WRITE_END 1
#define READ_END 0

int main(void) {

    int fd[2];             // sort <===> head
    int fd1[2];            //  du  <===> sort

    pipe(fd);

    switch (fork()) {
        case 0:            // Are we in sort?
             pipe(fd1);    // If yes, let's make a new pipe!

             switch (fork()) {
                 case 0:   // Are we in du?
                     dup2(fd1[1], STDOUT_FILENO);
                     close(fd1[0]);
                     close(fd1[1]);
                     execl("/usr/bin/du", "du", "..", NULL);
                     exit(1);

                 default:
                     /* If not in du, we're in sort! in the middle!
                        Let's set up both input and output properly.
                        We have to deal with both pipes */
                     dup2(fd1[0], STDIN_FILENO);
                     dup2(fd[1], STDOUT_FILENO);
                     close(fd1[0]);
                     close(fd1[1]);
                     execl("/usr/bin/sort", "sort (flags if needed)", (char *) 0);
                     exit(2);
             }

            exit(3);

        default:            // If we're not in sort, we're in head
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            close(fd[1]);
            execl("/usr/bin/head", "head (flags if needed)", (char *) 0);
            exit(4);

    }   
}