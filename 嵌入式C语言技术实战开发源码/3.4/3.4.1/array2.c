#include <stdio.h>
int main(void)
{
	//初始化
	int array[5] = {0,1,2,3,4};
	//遍历方式
	int i ; 
	for(i = 0 ; i < 5 ; i++)
	{
		printf("array[%d] : %d \n" , i , array[i]);
	}
}

