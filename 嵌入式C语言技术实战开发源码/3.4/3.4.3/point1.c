#include <stdio.h>
int main(void)
{
	int a = 100 ; 
	//  &  取地址符	
	//int *p ;  //定义一个指针   
	//没有初始化过的栈空间的指针     野指针
	int *p = NULL ; 
	//如果对空  简引用，会段错误
	p = &a ; 
//间接引用  符号*称为引用符
	*p = 200 ;  //改变a的值
	printf("address:%p p:%p a:%d \n" , &a , p , a);
	return 0 ; 
}


