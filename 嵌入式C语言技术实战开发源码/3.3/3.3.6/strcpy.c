#include <string.h>
int main(void)
{
	char *src = "hello world";
	char dest[20] ; 
	char *p = NULL;
	strcpy(dest , src);
	printf("src:%s \ndest:%s\n" , src , dest);
	return 0 ; 
}

