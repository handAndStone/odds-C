#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

static void showtimes(void)
{
	double ticks;
	struct tms tinfo;
	if ( (ticks=(double)sysconf(_SC_CLK_TCK)) == -1 )
	{
		perror("Failed to determine clock ticks per seccond");
	}
	else if ( times(&tinfo) == (clock_t)-1)
	{
		perror("Failed to get times infomation");
	}
	else
	{
		fprintf(stderr,"User time:                %8.3f secconds\n",tinfo.tms_utime/ticks);
		fprintf(stderr,"System time:              %8.3f secconds\n",tinfo.tms_stime/ticks);
		fprintf(stderr,"Children's user time:     %8.3f secconds\n",tinfo.tms_cutime/ticks);
		fprintf(stderr,"Children's system time:   %8.3f secconds\n",tinfo.tms_cstime/ticks);
	}
}

int main()
{
	printf("---------------开始------------------\n");
	if(atexit(showtimes))
	{
		fprintf(stderr,"Failed to install showtime exit handler\n");
		return 1;
	}
	return 0;
}
