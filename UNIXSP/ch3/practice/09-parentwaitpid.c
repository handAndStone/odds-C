#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	printf("----------start------------\n");

	pid_t childpid;
	childpid=fork();

	if(childpid == -1)
	{
		perror("Failed to fork");
		return 1;
	}
	if(childpid == 0)
	{
		fprintf(stderr,"I am child %u\n",getpid());
		sleep(10);
	}
	else if ( wait(NULL) != childpid )
	{
		fprintf(stderr,"A signal must have interrupted the wait!\n");
	}
	else
	{
		fprintf(stderr,"I am parent %u wait child %u\n",getpid(),childpid);
	}
	printf("-----------end-------------\n");
	return 0;
}
