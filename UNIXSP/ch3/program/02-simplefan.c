#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	printf("-------------start---------------\n");
	pid_t childpid=0;
	int i,n;
	 
	if(argc!=2)
	{
		fprintf(stderr,"Usage:%s processes\n",argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	for(i=0;i<n;i++)
	{
		childpid=fork();
		if(childpid <= 0)
		{
			break;
		}
	}
	sleep(1);
	fprintf(stderr,"i:%d  process ID:%u  parent ID:%u  child ID:%u\n",i,getpid(),getppid(),childpid);
	printf("-------------end---------------\n");
	return 0;
}

