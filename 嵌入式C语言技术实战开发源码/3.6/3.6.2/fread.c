#include <stdio.h>
#include <unistd.h>

int main()
{
	FILE *filp = NULL ;	
	filp = fopen("text.txt" , "r");
	if(NULL == filp)
	{
		perror("open file fail");
		return -1 ; 
	}
	char buf[11] = {0};
	int len = fread(buf , 11 , 1 , filp);
	if(len < 0)
		printf("read fair!\n");
	buf[11] = '\0';
	printf("buf:%s\n",buf);
	fclose(filp);
	return 0 ; 
}

