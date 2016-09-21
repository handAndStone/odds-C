#include <stdio.h>
#include <signal.h>
//	printf 的内容是否有\n有很大的影响
void main()
{
	printf("----------开始-------------\n");
	int status=0;
	status=raise(SIGTERM);
	if(status == -1)
	{
		perror("Failed to raise SIGTERM");
	}
	printf("----------结束-------------\n");
}
