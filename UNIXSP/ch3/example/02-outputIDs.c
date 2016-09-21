#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("------------start----------------\n");
	printf("My real user ID is        %u\n",getuid()  );
	printf("My effective user ID is   %u\n",geteuid() );
	printf("My real group ID is       %u\n",getgid()  );
	printf("My effective group ID is  %u\n",getegid() );
	printf("-------------end-----------------\n");
}
