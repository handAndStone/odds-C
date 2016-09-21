#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	printf("----------start-----------\n");
	pid_t childpid;
	int i, n;
	pid_t waitreturn;
	if (argc != 2)
	{
		fprintf(stderr,"Usage:%s processes\n",argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	for(i=1;i<n;i++)
	{
		childpid = fork();
		if(childpid != 0)
		{
			break;
		}
	}
	
	waitreturn = wait(NULL);
	while(childpid != waitreturn)
	{
		if( (waitreturn == -1)&&(errno != EINTR) )
		{
			break;
		}
	}
	fprintf(stderr,"I am process %u, my parent is %u\n",getpid(),getppid());
	printf("-----------end------------\n");
	return 0;
}
