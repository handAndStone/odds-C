#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("I'm process               %u\n",getpid());
	printf("My parent is              %u\n",getppid());
	printf("My real user ID is        %u\n",getuid());
	printf("My effective user ID is   %u\n",geteuid());
	printf("My real group ID is       %u\n",getgid());
	printf("My effective group ID is  %u\n",getegid());
	return 0;
}
