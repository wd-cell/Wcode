#include <stdio.h>
#include <string.h>
int main(void)
{
	char *src = "hello world";
	char dest[1] ; 
	char *p = NULL;
	strcpy(dest , src);
	printf("src:%s \ndest:%s\n" , src , dest);
	return 0 ; 
}

