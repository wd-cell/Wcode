#include <stdio.h>
int main(void)
{
	int num ; 
	int aa = (int)&num ;
	printf("please input num:\n");
	scanf("%d" , aa);
	printf("num:%d \n" , num);
	return 0 ; 
}

