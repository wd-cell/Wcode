#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest[100] = "hello kitty" ; 
	char *p = " this is a cat" ; 
	char *ret = NULL; 
	ret = strcat(dest , p);
	printf("ret:%s\ndest:%s\np:%s\n", ret , dest , p);
	return 0 ; 
}

