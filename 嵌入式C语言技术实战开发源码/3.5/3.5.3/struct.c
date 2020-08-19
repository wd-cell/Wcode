#include <stdio.h>
//32位系统上，结构体在没指定对齐的时候，默认以四字节进行对齐 
typedef struct __ST
{
	int id ; 		//4
	char *name ; 	//4
	float math ;	//4
}ST;
int main()
{
	ST st ;
	//获取结构体的第一个元素的首地址
	int *ptr_0 = (int *)(&st);
	printf("st:   %p    ptr:   %p \n",&st,ptr_0);
	//对结构体第一个元素赋值 
	*ptr_0 = 100 ;
	printf("*ptr_0 = %d\n",*ptr_0);
	//获取结构体的第二个元素的首地址
	char **ptr_1 = (char **)((int)&st+4) ;
	printf("ptr_1:%p\n",ptr_1);
	//对结构体的第二个元素赋值 
	*ptr_1 = "hello world";
	printf("ptr_1:%s\n",*ptr_1);
	//获取结构体的第三个元素的首地址，根据对齐原则偏移算出第三个元素的地址 
	float *ptr_2 = (float *)((int)&st+8) ;
	printf("ptr_2:%p \n",ptr_2);
	//对结构体的第三个元素进行赋值 
	*ptr_2 = 96.78 ;
	printf("ptr_2:%.2f \n",*ptr_2);
	//输出结构体中所有成员的值 
	printf("st.id = %d   st.name = %s   st.math = %.2f\n",st.id,st.name,st.math);
    return 0;
}

