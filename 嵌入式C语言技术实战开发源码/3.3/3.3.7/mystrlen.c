#include <stdio.h>
#include <string.h>
//只读传参
int mystrlen(const char *str);
int main(void)
{
	//字符串以尾零结尾     '\0' == null  ascii
	char *p = "hello world" ;   
	printf("strlen:%d \n" , strlen(p));
	printf("strlen:%d \n" , mystrlen(p));

	return 0 ; 
}
int mystrlen(const char *str)
{
	int count = 0 ; 
	while((*str++ != '\0') && ++count);
	return count ; 
}

