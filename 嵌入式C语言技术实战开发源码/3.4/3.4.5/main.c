#include <stdio.h>
#include "vendor.h"

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

