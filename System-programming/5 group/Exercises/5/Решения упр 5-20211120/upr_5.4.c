#include <stdio.h>

#define	DATEPATH "/bin/date"
#define	DATE "date"
#define	ERROR -1

main(argc,argv)
int argc;
char *argv[];
{
   int rc =0;

   if (execlp("grep","grep","int",argv[1],0) == ERROR) {
      perror(DATEPATH);
       printf("\n123This line is never printed\n");
      rc = 1;
   }
    else {
       printf("This line is never printed\n");
    }
    exit(rc);
}
