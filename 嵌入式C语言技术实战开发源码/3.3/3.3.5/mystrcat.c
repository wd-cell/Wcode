#include <stdio.h>
char *mystrcat(char *dest , const char *src);
int main(void)
{
	char dest[100] = "hello kitty" ; 
	char *p = " this is a cat" ; 
	char *ret = NULL; 
	ret = mystrcat(dest , p);
	printf("ret:%s\ndest:%s\np:%s\n", ret , dest , p);
	return 0 ; 
}
char *mystrcat(char *dest , const char *src)
{
	char *tmp = dest ;
	//偏移到最后面
	while(*tmp)
		 tmp++ ; 
	while(*tmp++ = *src++) ; 
	return dest ; 
}

