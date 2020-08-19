#include <stdio.h>
#define f(x) x*x
int main( )  
{  
	int x,y,z ;
	x = 2 ; 
	y = 2 ;
	z = f(x+y) + f(y);
	printf("z=%d\n",z);  
	return 0 ; 
}

