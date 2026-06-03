#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	if ( fork() )
	{
		execlp(argv[1],argv[1],NULL);
	}
	else
	{
		execlp(argv[2],argv[2],argv[3],NULL);
	}
}
