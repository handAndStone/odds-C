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
	int bytesread;
	int childpid;
	int status;
	int fd,fd1,fd2;
	if(argc !=3)
	{
		fprintf(stderr,"Usage:%s from_file to to_file\n",argv[0]);
		return 1;
	}
	fd1 = open(argv[1],O_RDONLY);
	if(fd1 == -1)
	{
		perror("Failed to open input file");
		return 1;
	}
	fd2 = open(argv[2],O_RDONLY);
	if(fd2 == -1)
	{
		perror("Failed to create input file");
		return 1;
	}
	childpid = fork();
	if(childpid == -1)
	{
		perror("Failed to fork");
		return 1;
	}
	if(childpid > 0)
	{
		fd = fd1;
		bytesread = copyfile(fd,STDOUT_FILENO);
	}
	else
	{
		fd = fd2;
		bytesread = copyfile(fd,STDOUT_FILENO);
	}
//	if(wait(NULL) == childpid)
//	{
		fprintf(stderr,"Bytes read: %d\n",bytesread);
//	}
//	else
//	{
//		fprintf(stderr,"Bytes read: %d\n",bytesread);
//	}
	status = close(fd);
	if(status == -1)
	{
		perror("Failed to close file");
	}
	printf("-------------end--------------\n");
	return 0;
}












