#include <stdio.h>  
#include <stdlib.h>
//用指针的方式检测机器的大小端模式
int small_port()
{
	int a = 1 ; 
	char b = *((char *)(&a)) ;
	return b ;
}
int main(void)
{
	int i = small_port();
	if(1 == i)
		printf("小端模式\n");
	else
		printf("大端模式\n");
	return 0 ;	
}

