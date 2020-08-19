#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL ;
	int i ;
	p = malloc(sizeof(int));
	if(NULL == p)
	{
		printf("内存分配失败!\n"); 
		return -1 ;
	}
	*p = 100 ;
	printf("malloc_size:%p  *p:%d\n",p,*p);
	free(p);
	//再释放一次
	free(p); 
	return 0 ;	
}

