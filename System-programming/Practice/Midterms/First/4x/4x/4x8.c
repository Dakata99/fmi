#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	close(1);
	int fd=open(argv[1],O_CREAT | O_TRUNC | O_RDWR,0664);
	execlp("grep","grep","abc","aaa",NULL);
}
