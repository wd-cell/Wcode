#include <stdio.h>
//strcpy拷的时候有带尾零
char *mystrcpy(char *dest , const char *src);
int main(void)
{
	char *src = "hello kitty";
	char dest[100];
	mystrcpy(dest , src);
	printf("dest:%s\n" , dest);
	return 0 ; 
}

char *mystrcpy(char *dest , const char *src)
{
	char *tmp = dest; 
	while(*tmp++=*src++) ; 
	return dest ; 
}

