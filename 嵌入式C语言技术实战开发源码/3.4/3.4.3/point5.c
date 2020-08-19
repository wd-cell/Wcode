#include <stdio.h>
//函数指针类型定义
typedef int (*func_t)(const char *fmt , ...) ;
typedef int (*myput_t)(int ch);
func_t ppp = printf ;
myput_t uuu = putchar;
//函数调用就是在函数指针之后加()
int main(void)
{
	printf("putchar:%p printf:%p \n" , putchar , printf);	
	putchar('A');
	putchar('\n');
	ppp("hello kitty ... \n");
	uuu('B');	
	return 0 ; 
}

