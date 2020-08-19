#include <stdio.h>
#define  PRINT_HELLO     \
		printf("hello world \n");\
		printf("hello kitty \n");
//最后一行不加反斜杠

int main(void)
{
	//  反斜杠  延续之前的指令属性
	//注释     \
	helloworld
	PRINT_HELLO 
	#if 0
	//被注释
	//#if 1 相反
	#else
	//没有被注释
	#endif
	return 0 ; 
}

