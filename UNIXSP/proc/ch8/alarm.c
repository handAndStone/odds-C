#include <stdio.h>
#include <unistd.h>

//	alarm 默认动作是终止进程

void main()
{
	printf("--------开始-----------\n");
	unsigned int alarm_t;
	alarm_t=alarm(10);
	for(;;);
	printf("--------结束-----------\n");
}
