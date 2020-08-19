#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//人物类 
struct human
{
	int id ; 
	char *name ;
	void *humandata ;
	void (*handler_humandata)(int id , char *name ,struct human human_st);	
};

//方法1 
void print_data(int id , char *name , struct human human_st)
{
	printf("Id:%d name is %s , he is a %s\n", id , name , human_st.humandata);
}
//方法2 
void print_data1(int id , char *name , struct human human_st)
{
	printf("Id:%d name is %s , he hava %d money!\n", id , name , human_st.humandata);
}
int main(void)
{
	//1、定义并初始化第一个结构体成员
	struct human xiaoming ;
	xiaoming.id = 1010 ;
	xiaoming.name = "xiaoming";
	xiaoming.humandata = "student" ;
	xiaoming.handler_humandata = print_data ;
	xiaoming.handler_humandata(xiaoming.id , xiaoming.name , xiaoming) ;
	//2、定义并初始化第二个结构体成员
	struct human AA ;
	AA.id = 3366 ; 
	AA.name = "AA" ;
	AA.humandata = (void *)1000000 ; 
	AA.handler_humandata = print_data1 ;
	AA.handler_humandata(AA.id , AA.name , AA);
	return 0 ;
}

