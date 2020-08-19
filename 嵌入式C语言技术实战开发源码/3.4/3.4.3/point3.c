#include <stdio.h>
int main(void)
{
	char *p ; 
	int *in ; 
	float *fl ;
	double *dou ;
	void *v ; 
	printf("char:%p  int:%p  float:%p  double:%p  void:%p \n" , 
	p , in , fl , dou , v);
	printf("char:%p  int:%p  float:%p  double:%p  void:%p \n" , 
	p + 1, in + 1, fl + 1, dou + 1, v + 1);
	return 0 ; 
}

