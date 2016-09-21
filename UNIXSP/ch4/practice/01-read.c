#include <stdio.h>
#include <unistd.h>

void main ()
{
	printf("------------start--------------\n");
	char *buf;
	ssize_t bytesread=0;
	bytesread = read(STDIN_FILENO,buf,100);
	perror("ERROR");
	printf("Entered:%s\n",buf);
	printf("-------------end---------------\n");
}
