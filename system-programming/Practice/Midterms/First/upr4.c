#include <fcntl.h>
main()
{
int fd1,fd2,fd3;
char buf[20];
creat("fff",0777);
	fd1=open("fff",0);
		fd2=open("fff",1);
			fd3=open("fff",2);
			write(fd3,"hello",5);
		write(fd2,"worlds",6);
	read(fd1,buf,7);
	write(1,buf,7);
                close(fd2);
			write(fd3,"oops",4);
	read(fd1,buf,7);
	write(1,buf,7);
}
