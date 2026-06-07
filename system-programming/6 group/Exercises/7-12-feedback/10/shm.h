#ifndef _SHM_H_
#define _SHM_H_

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define ERRSHMCTL   "SHMCTL ERROR!"
#define ERRSHMGET   "SHMGET ERROR!"
#define ERRSHMAT    "SHMAT ERROR!"
#define ERRSHMDT    "SHMDT ERROR!"

#define SHM_KEY     1234
#define MAXLINE     1024

void terminate(char* err) { perror(err); exit(EXIT_FAILURE); }

#endif