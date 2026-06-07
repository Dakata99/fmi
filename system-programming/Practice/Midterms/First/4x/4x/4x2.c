#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	execlp("wo","who",NULL);
	printf("bachka");
}
