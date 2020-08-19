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
	//对指针置空
	p = NULL ;
	//多次释放
	for(i = 0 ; i < 100 ; i++)
		free(p);
	printf("malloc_size:%p\n",p);
	return 0 ;	
}

