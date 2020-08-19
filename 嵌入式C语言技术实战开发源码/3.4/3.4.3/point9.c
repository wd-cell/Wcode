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
	//释放内存
	free(p);
	//将指针指向空
	p = NULL ;
	printf("malloc_size:%p\n",p);
	return 0 ;	
}

