#include <stdio.h>

//函数指针类型定义
typedef int (*func_t)(const char *fmt , ...) ;
typedef int (*myput_t)(int ch);
//typedef int *    UU32 ; 

int *p = (void *)0x804829C ;  //整型指针 
//int (*ppp)(const char *fmt , ...) = (void *)0x804829C;  //函数指针
int (*add)(int a , int b) = (void *)0x804829C;

//func_t  ppp  = (void *)0x804829C ; 
//myput_t uuu  = (void *)0x80482AC ; 

func_t ppp = printf ;
myput_t uuu = putchar;

//函数调用就是在函数指针之后加()
int main(void)
{
	printf("putchar:%p printf:%p \n" , putchar , printf);	
	putchar('A');
	ppp("hello kitty ... \n");
	uuu('B');	
//	printf("hello world\n");
	return 0 ; 
}

