#include <stdio.h>
int main(void)
{
	char *ch   ; 
	int * in   ; 
	float * f  ; 
	double *dou ; 
	void * v   ;   //万能指针
	printf("char:%d  int:%d float:%d double:%d void:%d \n" , 
	sizeof(ch) , sizeof(in) , sizeof(f),sizeof(dou) , sizeof(v));
	return 0 ; 
}

