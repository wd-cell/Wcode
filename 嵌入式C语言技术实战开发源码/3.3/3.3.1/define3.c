#include <stdio.h>
//产生条件编译   定义 __DEBUG__
#define   __DEBUG__
//解定义  __DEBUG__   这个以后__DEBUG__将没有被定义过
#undef    __DEBUG__
//如果没有定义__DEBUG__ 定义__DEBUG__
#ifndef   __DEBUG__
#define   __DEBUG__
#endif   //__DEBUG__ 
//#define  WIN32
#define  LINUX
//程序编译时，一般情况会产生两个版本
//#define  DEBUG
//DEBUG   RELEASE
//WIN32   LINUX
int main(void)
{
	//条件编译
	//如果__DEBUG__有被define 条件
	//以下代码会被编译，如果没有define过，不会被编译
	#ifdef  __DEBUG__
	printf("hello world \n");
	#endif  //__DEBUG__
	#ifdef  WIN32
	printf("hahaha this is in windows \n");
	#endif  //WIN32
	#ifdef  LINUX
	printf("hehehe this is in Linux   \n");
	#endif  //LINUX
	//可以当做条件判断
	#if   defined(WIN32) && defined(LINUX)
	printf("this is a test ... \n");
	#endif
	return 0 ; 
}

