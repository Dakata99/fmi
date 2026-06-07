#include "syshdr.h"

/* Print a message and return to caller */
void err_doit(int err_flag, const char* frm, va_list ap)
{
    int err_save = errno;
    char msg[MAXLINE];
    
    vsprintf(msg, frm, ap);

    if (err_flag) sprintf(msg + strlen(msg), ": %s", strerror(err_save));

    strcat(msg, "\n");
    fflush(stdout);
    fputs(msg, stderr);
    fflush(NULL);
}

/* After error related to system call. Print a message and exit. */
void err_sys_exit(char* msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    err_doit(1, msg, ap);
    va_end(ap);
    exit(1);
}

/* After error related to system call. Print a message and return. */
void err_sys_return(char* msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    err_doit(1, msg, ap);
    va_end(ap);
}

/* After error unrelated to system call. Print a message and exit. */
void err_exit(char* msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    err_doit(0, msg, ap);
    va_end(ap);
    exit(1);
}

/* After error unrelated to system call. Print a message and return. */
void err_return(char* msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    err_doit(0, msg, ap);
    va_end(ap);
}