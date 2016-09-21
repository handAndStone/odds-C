#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("-----------start--------------\n");
	pid_t childpid;

	childpid = fork();
	if(childpid == -1)
	{
		perror("Failed to fork");
		return 1;
	}
	if(childpid == 0)
	{
		printf("I'm child %u\n",getpid());
	}
	else
	{
		printf("I'm parent %u\n",getpid());
	}
	printf("------------end---------------\n");
}
