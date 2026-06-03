#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	exit(0);
	execvp(argv[1],argv+1);
}
