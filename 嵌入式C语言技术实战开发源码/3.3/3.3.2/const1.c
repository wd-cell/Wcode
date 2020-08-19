#include <stdio.h>
int main(void)
{
	//常量区
	int const a = 100 ; 
	const int b = 200 ; 
	//常量变量  只读变量  不可以修改    其中int const ==  const int
	printf("a:%d b:%d \n" , a , b ); 
	return 0 ; 
}

