#include <stdio.h>
#include <fcntl.h>

#define ERROR -1

main()
{
	int i,fd1,fd2,status;
        if ((fd1=open("ff",O_WRONLY|O_CREAT,0777))== -1)
              {printf("ERROR\n"); exit(1);}
              printf("%d\n",fd1);
   if ( fork()==0 )  {
        write(fd1,"HELLO1",6);
        write(fd1,"HELLO2",6);}

   else {
        //wait(&status);
        write(fd1,"HELLO3",6);
        close(fd1);
        write(fd1,"HELLO4",6);}
}
