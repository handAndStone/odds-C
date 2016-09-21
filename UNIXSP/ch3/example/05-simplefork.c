#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("----------start------------\n");
	int x;
	x=0;
	fork();
	x =1;
	printf("I'm a process %u and my \"x\" is %u\n",getpid(),x);
	printf("-----------end-------------\n");
}
