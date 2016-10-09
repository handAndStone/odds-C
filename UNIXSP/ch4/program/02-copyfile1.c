#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#define BLKSIZE 15
int copyfile(int fromfd,int tofd)
{
	char *bp;
	char buf[BLKSIZE];
	int bytesread,byteswriten;
	int totalbytes = 0;

	for(;;)
	{
		while (((bytesread=read(fromfd,buf,BLKSIZE))==-1) && (errno=EINTR))
		{
			;
		}
		if(bytesread <= 0)
		{
			break;
		}
		bp=buf;
		while(bytesread > 0)
		{
			while(((byteswriten=write(tofd,bp,bytesread))==-1)&&(errno==EINTR))
			{
				;
			}
			if(byteswriten<0)
			{
				break;
			}
			totalbytes += byteswriten;
			bytesread -= byteswriten;
		}
		if(byteswriten == -1)
		{
			break;
		}
	}
	return totalbytes;
}

int main()
{
	printf("------------start-------------\n");
	int numbytes;

	numbytes = copyfile(STDIN_FILENO,STDOUT_FILENO);
	fprintf(stderr,"Number of bytes copied: %d\n",numbytes);
	printf("-------------end--------------\n");
	return 0;
}












