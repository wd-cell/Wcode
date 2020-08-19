#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
//结构体类型声明
//没有空间
struct student
{
	int a ;   //结构体成员
	int b ; 
};
int main(void)
{
	//结构体定义 
	//栈区
	struct student stu1 ; 
	//结构体定义加初始化
	struct student stu = {10 , 20};
	//结构体成员访问  变量  .
	stu1.a = 100 ; 
	stu1.b = 200 ; 
	printf("stu.a:%d stu.b:%d stu1.a:%d stu1.b:%d \n" , 
	stu.a , stu.b , stu1.a , stu1.b);
	//在堆区定义结构体指针
	struct student *p = NULL ; 
	//p = malloc(sizeof(struct student));
	p = malloc(100);
	if(NULL == p)
	{
		fprintf(stderr , "malloc struct student p fail errno:%d\n" , errno);
		//系统报错
		perror("nomemory");
		//内存分配失败   没有内存
		return -ENOMEM ; 
	}
	//结构体指针访问   ->
	p->a = 300 ; 
	p->b = 400 ; 
	printf("p->a:%d p->b:%d \n" , p->a , p->b);
	//堆空间释放
	free(p);
	return 0 ; 
}

