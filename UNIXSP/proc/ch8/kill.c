#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
	printf("------开始------\n");
	int status=0;
	status=kill(getpid(),SIGTERM);
	if(status == -1 )
	{
		perror("Failed to kill myself.");
	}
	printf("------结束------\n");
}

