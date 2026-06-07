#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	int i=0;
	for(;i<10;i++)
	{
		execlp("who","who",NULL);
	}
}
