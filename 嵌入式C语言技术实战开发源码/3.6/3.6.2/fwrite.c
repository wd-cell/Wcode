#include <stdio.h>
#include <unistd.h>

int main()
{
	FILE *filp = NULL ;	
	filp = fopen("text.txt" , "w+");
	if(NULL == filp)
	{
		perror("open file fail");
		return -1 ; 
	}
	char *p = "hello world" ;
	int len = fwrite(p , strlen(p) , 1 , filp);
	if(len < 0)
		printf("write fair!\n");
	printf("fwrite success!\n");
	fclose(filp);
	return 0 ; 
}

