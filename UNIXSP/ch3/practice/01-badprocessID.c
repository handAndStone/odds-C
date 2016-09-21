#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("------------start--------------\n");
	pid_t childpid;
	pid_t mypid;

	mypid=getpid();

	childpid=fork();
	if(childpid == -1)
	{
		perror("Failed to fork");
		return 1;
	}
	if(childpid == 0)
	{
		printf("I am child %u, ID = %u\n",getpid(),mypid);
	}
	else
	{
		printf("I am parent %u, ID = %u\n",getpid(),mypid);
	}
	printf("-------------end---------------\n");
	return 0;
}
