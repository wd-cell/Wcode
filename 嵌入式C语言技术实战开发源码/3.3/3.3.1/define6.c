#include <stdio.h>
//如果在不确定是否为表达式时，加()
#define   ADD(x ,y)      			((x)+(y))
int main(void)
{
	int sum ; 
	sum = ADD(10,20);
	printf("sum:%d \n" , sum);
	return 0 ; 
}

