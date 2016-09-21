//this is used for suring the exit status of children process

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void showreturnstatus(void)
{
	pid_t childpid;
	int status;

	childpid=wait(&status);
	if(childpid == -1)
	{
		perror("Failed to wait for child");
	}
	else if(WIFEXITED(status)  && !WEXITSTATUS(status))  //WEXITSTATUS(status) get the return value of the child process.
	{
		printf("Child %u terminated normally\n",childpid);
	}
	else if(WIFEXITED(status))
	{
		printf("Child %u terminated with a return status %d\n",childpid,WEXITSTATUS(status));
	}
	else if(WIFSIGNALED(status))
	{
		printf("Child %u terminated due to a uncaught signal %d\n",childpid,WTERMSIG(status));
	}
	else if(WIFSTOPPED(status))
	{
		printf("Child %u stopped due to a signal %n\n",childpid,WSTOPSIG(status));
	}
}

int main()
{
	printf("--------------start----------\n");
	fork();
	showreturnstatus();
	printf("--------------end------------\n");
	return 0;
}
