#include <stdio.h>
int main(void)
{
	int a = 100 ; 
	int b = 200 ;
	//都是指针
	const int *p = &a ; 
	int *const q = &a ; 
	//改指针
	//p = &b ;  // 可以这样来表示
	//改值
	//*p = 300 ; 
	//const int *p ; 可以改指针指向的地址，不能改指针指向地址的值
	//改指针
	//q = &b ;   //不能改指针，这种做法错误
	//改值
	//*q = 300 ; 
	//int *const q ; 不可以改指针，可以改指针指向地址的值
	//双方都不可以改动，但是注意,一般情况下，必须初始化
	const int *const o = &a ; 
	printf("p:%d q:%d \n" , *p , *q);	
	printf("a:%d  b:%d \n" ,a  , b);
	return 0 ; 
}

