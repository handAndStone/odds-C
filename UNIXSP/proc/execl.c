#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t childpid;
	childpid=fork();
	if(childpid == -1)
	{
		perror("Failed to fork");
		return 1;
	}
	if(childpid == 0)
	{
		execl("/bin/ls","ls","-1",NULL);
		perror("Child failed to exec ls");
		return 1;
	}
	if(childpid != wait(NULL))
	{
		perror("Parent failed to wait due to signal or error");
		return 1;
	}
	return 0;
}
