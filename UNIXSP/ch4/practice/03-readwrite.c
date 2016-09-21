#include <stdio.h>
#include <unistd.h>

#define BLKSIZE 20

int main()
{
	printf("---------start------------\n");
	char buf[BLKSIZE]={};
	read(STDIN_FILENO,buf,BLKSIZE);
	write(STDOUT_FILENO,buf,BLKSIZE);
	printf("----------end-------------\n");
	return 0;

}
