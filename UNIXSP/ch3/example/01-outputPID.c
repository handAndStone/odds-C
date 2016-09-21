#include <stdio.h>
#include <unistd.h>

int main ()
{
	printf("---------start------------\n");
	
	printf("I'm process %u\n",getpid());
	printf("My parent is %u\n",getppid());
	
	printf("----------end-------------\n");
}
