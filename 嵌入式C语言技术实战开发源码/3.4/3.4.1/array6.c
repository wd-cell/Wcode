#include <stdio.h>
int main(void)
{
	int i ; 
	int array[5] = {1,2,3,4,5};
	array[4] = 10 ; 
	array[5] = 20 ;
	array[6] = 30 ; 
	for(i = 0 ; i < 10 ; i++)
	{
		printf("array[%d]:%d\n",i,array[i]);
	}
	return 0 ; 
}

