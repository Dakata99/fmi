#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	execlp(argv[1], argv[1] ,argv[2], argv[3],NULL);
}
