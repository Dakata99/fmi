#ifndef SYSHDR_H
#define SYSHDR_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

#define MAXLINE     1024

#define ERRNOFILE   "Could not open file!"

/* Print a message and return to caller */
void err_doit(int, const char*, va_list);

/* After error related to system call. Print a message and exit. */
void err_sys_exit(char* msg, ...);

/* After error related to system call. Print a message and return. */
void err_sys_return(char* msg, ...);

/* After error unrelated to system call. Print a message and exit. */
void err_exit(char* msg, ...);

/* After error unrelated to system call. Print a message and return. */
void err_return(char* msg, ...);

#endif