#include <fcntl.h>
main()
{
int fd1,fd2,fd3;
char buf[20];
open("fff",O_CREAT|O_TRUNC|O_RDWR,0777);
	fd1=open("fff",O_RDONLY);
		fd2=open("fff",O_WRONLY);
			fd3=open("fff",O_RDWR);
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
