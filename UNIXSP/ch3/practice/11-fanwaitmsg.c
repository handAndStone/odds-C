#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	printf("--------start---------\n");
	pid_t childpid = 0;
	int i, n;

	if(argc != 2)
	{
		fprintf(stderr,"Usage:%s processes\n",argv[0]);
		return 1;
	}
	n = atoi (argv[1]);
	for(i =1 ;i<n;i++)
	{
		childpid = fork();
		if(childpid <= 0)
		{
			break;
		}
	}
	for(;;)
	{
		childpid=wait(NULL);
		if((childpid == -1) && (errno != EINTR))
		{
			break;
		}
	}
	fprintf(stderr,"I am process %u, my parent is %u\n",getpid(),getppid());
	printf("---------end----------\n");
}
