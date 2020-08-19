#include <stdio.h>

int add_ret() ;

int add(int a , int b , int (*add_value)())
{
	return (*add_value)(a,b);
}

int main(void)
{
	int sum = add(3,4,add_ret);
	printf("sum:%d\n",sum);
	return 0 ;
} 

int add_ret(int a , int b)
{
	return a+b ;
}

