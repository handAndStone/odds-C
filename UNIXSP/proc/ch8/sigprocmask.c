#include <signal.h>
#include <stdio.h>


//	SIG_BLOCK	向当前被阻塞的信号中添加一个信号集
//	SIG_UNBLOCK	当前阻塞的信号中删除信号集
//	SIG_SETMASK	将指定的信号集设置为被阻塞的信号集
void main()
{
	printf("----------开始-------------\n");
	sigset_t newsigset;
	if	((sigemptyset(&newsigset) == -1) ||
		 (sigaddset(&newsigset,SIGINT) == -1))
	{
		perror("Failed to initialize the signal set");
	}
	else if(sigprocmask(SIG_BLOCK,&newsigset,NULL) == -1)
	{
		perror("Failed to block SIGINT");
	}
	printf("----------结束-------------\n");
}
