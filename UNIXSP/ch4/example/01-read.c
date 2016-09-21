#include "stdio.h"
#include "unistd.h"

void main()
{
	printf("----------start-------------\n");
	char buf[15]={};			//Strong recommend initialized,otherwise，there will be some unpredicted problems.
	int i = 0;
	ssize_t bytesread;
	bytesread = read(STDIN_FILENO,buf,15);
	if(bytesread == -1)
	{
		perror("Failed to read");
	}
	else
	{
		for(i = 0;i<15; i++)
		printf("%d:%c %d\n",i,buf[i],buf[i]);
	}
	printf("-----------end--------------\n");
}
