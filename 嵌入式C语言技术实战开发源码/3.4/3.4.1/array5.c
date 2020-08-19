#include <stdio.h>
#define   NR(x)    (sizeof(x)/sizeof(x[0]))
int main(void)
{
	//数组有自动计数功能
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	//相同类型的变量的集合体
	//int array[5] ; 
	printf("arraysize:%d  \n" , sizeof(array));
	printf("number:%d \n" , sizeof(array)/sizeof(array[0]));
	printf("number:%d \n" , NR(array));
	int i ; 
	
	for(i = 0 ; i < NR(array) ; i++)
	{
		printf("array[%d]:%d \n" , i , array[i]);
	}

	return 0 ; 
}

