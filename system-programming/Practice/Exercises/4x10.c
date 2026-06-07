#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	if ( fork() )
	{
		close(1);
		int fd=open("x1",O_CREAT | O_TRUNC | O_RDWR,0664);
		execlp(argv[1],argv[1],NULL);
	}
	else
	{
		execlp(argv[2],argv[2],argv[3],NULL);
	}
}
