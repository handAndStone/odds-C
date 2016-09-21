#include <string.h>
#include <stdio.h>

void main ()
{
	printf("-----------------开始------------------\n");
	char *s="a b  c   d";//10个字节，不算最后的\0
	char temp[11];
	strcpy(temp,s);
	int i=0;
	int len=strlen(s);
	int real_len=len+1; //加一个\0
	printf("\"%s\"的长度:%d\n",s,len);
	for(i=0;i<real_len;i++)
	{
		printf("*(s+%d) = %c = %d(D)\n",i,*(s+i),*(s+i));
	}
	printf("-----------------------------------\n");
	char *result=strtok(temp," ");
	for(i=0;i<real_len;i++)
	{
		printf("*(result+%d) = %c = %d(D)\n",i,*(result+i),*(result+i));
	}
	printf("-----------------------------------\n");
	char *result1 = strtok(NULL," ");
	for(i=0;i<real_len;i++)
	{
		printf("*(result+%d) = %c = %d(D)\n",i,*(result+i),*(result+i));
	}
	printf("-----------------结束------------------\n");
}

	

