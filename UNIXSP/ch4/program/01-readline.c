#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int readline(int fd,char *buf,int nbytes)
{
	int numread = 0;
	int returnval;

	while(numread < nbytes - 1)
	{
		returnval = read(fd,buf+numread,1);
		if((returnval == -1) && (errno == EINTR))
		{
			continue;
		}
		if((returnval == 0) && (numread == 0))
		{
			return 0;
		}
		if(returnval == 0)
		{
			break;
		}
		if(returnval == -1)
		{
			return -1;
		}
		numread++;
		if(buf[numread-1] == '\n')
		{
			buf[numread]='\0';
			return numread;
		}
	}
	errno = EINVAL;
	return -1;
}

int main()
{
	printf("-----------start-------------\n");
	char line[10]={};   //Reserve last two bytes for '\n' and '\0'
	int i =0;
	while(readline(STDIN_FILENO,line,10) > 0)
	{
		printf("%s",line);
		if(strncmp(line,"exit",4) == 0)
		{
			return 0;
		}
	}
	printf("------------end--------------\n");
	return 0;
}
