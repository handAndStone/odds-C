#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLKSIZE 1024
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

#define READ_FLAGS O_RDONLY
#define WRITE_FLAGS (O_WRONLY | O_CREAT | O_EXCL)
#define WRITE_PERMS (S_IRUSR | S_IWUSR)

int main(int argc,char *argv[])
{
	printf("------------start-------------\n");
	int bytes;
	int status;
	int fromfd,tofd;
	if(argc !=3)
	{
		fprintf(stderr,"Usage:%s from_file to to_file\n",argv[0]);
	}
	fromfd = open(argv[1],READ_FLAGS);
	if(fromfd == -1)
	{
		perror("Failed to open input file");
		return -1;
	}
	tofd = open(argv[2],WRITE_FLAGS,WRITE_PERMS);
	if(tofd == -1)
	{
		perror("Failed to create input file");
		return -1;
	}
	bytes = copyfile(fromfd,tofd);
	if((status=close(fromfd)) == -1)
	{
		perror("Failed to close file");
	}
	if((status = close(tofd)) == -1)
	{
		perror("Faiied to close tofd");
	}
	printf("%d bytes copied from %s to %s\n",bytes,argv[1],argv[2]);
	printf("-------------end--------------\n");
	return 0;
}












