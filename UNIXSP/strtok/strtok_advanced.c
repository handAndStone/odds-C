#include <string.h>
#include <stdio.h>


void main()
{
	char *src1="a bc  def";
	char *src2="1 23  456";
	char *temp_src1=src1;
	char *temp_src2=src2;
	char *rest_start1=NULL;
	char *rest_start2;
	printf("------------------------------\n");
	printf("%s\n%s\n",temp_src1,temp_src2);
	printf("------------------------------\n");
	rest_start1 = strtok(temp_src1," ");
//	rest_start1 = (rest_start1 + strlen(*rest_start1));
//	char *rest_start2 = strtok(src2," ");
//	rest_start2 = (rest_start2 + strlen(*rest_start2));
//	printf("%s\n%s\n",rest_start1,rest_start2);
	printf("------------------------------\n");
}
