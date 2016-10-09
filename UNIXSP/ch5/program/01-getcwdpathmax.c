#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#ifndef PATH_MAX
#define PATH_MAX 255
#endif

int main()
{
	printf("----------start-------------\n");
	char mycwd[PATH_MAX];
	if(getcwd(mycwd,PATH_MAX) == NULL)
	{
		perror("Failed to get current working directory");
		return 1;
	}
	printf("Current working directory:%s\n",mycwd);
	printf("-----------end--------------\n");
	return 0;
}
