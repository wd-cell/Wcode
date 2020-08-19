#include <stdio.h>
#define  NR(x)  (sizeof(x)/sizeof(x[0]))
int main(void)
{
	//数组地址连续性
	int array[] = {1,2,3,4,5,6,7}; 
	int i ; 
	for(i = 0 ; i < NR(array)  ; i++)
		printf("array[%d]:%d \n" , i , *(array+i));
	return 0 ; 
}

