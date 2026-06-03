#include <fcntl.h>
main()
{
int fd1,fd2,fd3;
char buf[20];
creat("fff",0777);
	fd1=open("fff",0);
		fd2=open("fff",1);
			fd3=open("fff",2);
		write(fd2,"hello world",11);
			read(fd3,buf,6);
			write(1,buf,6);
	read(fd1,buf,5);
	write(1,buf,5);
			write(fd3,"chil",4);
	write(fd2,"!!!",3);
	read(fd1,buf,9);
	write(1,buf,9);
}
