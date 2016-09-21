#include <signal.h>
#include <stdio.h>

void main()
{
	printf("---------开始-----------\n");

	int status = 0;

	sigset_t test;
	status = sigismember(&test,SIGTERM);
	printf("新建信号集存在\"SIGTERM\"？\n");
	if(status == 1)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	
	sigemptyset(&test);
	status = sigismember(&test,SIGTERM);
	printf("信号集\"empty\"之后存在\"SIGTERM\"？\n");
	if(status == 1)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存杂\n");
	}

	sigfillset(&test);
	status = sigismember(&test,SIGTERM);
	printf("信号集\"fill\"之后存在\"SIGTERM\"？\n");
	if(status == 1)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}

	sigdelset(&test,SIGTERM);
	status = sigismember(&test,SIGTERM);
	printf("信号集\"delete SIGTERM\"之后存在\"SIGTERM\"？\n");
	if(status == 1)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	
	sigaddset(&test,SIGTERM);
	status = sigismember(&test,SIGTERM);
	printf("信号集\"add SIGTERM\"之后存在\"SIGTERM\"？\n");
	if(status == 1)
	{
		printf("存在\n");
	}
	else
	{	
		printf("不存在\n");
	}

	printf("---------结束-----------\n");
}
