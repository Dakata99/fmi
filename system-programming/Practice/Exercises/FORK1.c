#include <stdio.h>

#define ERROR -1

main()
{
	int i;

   if ( fork()==0 )  {printf("child --> pid= %d ppid= %d\n",getpid(),getppid());
	}
   else {
//      wait();
        printf("parent --> pid= %d, ppid= %d\n",getpid(),getppid());
	   for (i=1;i<= 1000000000 ;i++)  ;
        }
	printf("\n Common part of parent+child\n");
}
