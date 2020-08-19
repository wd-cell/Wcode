#include <stdio.h>
//没有命名的结构体
//定义变量只有
struct {
	int a ;
	int b ; 
//相同类型
}abc , aaa;
struct  {
	int a ; 
	int b ; 
}ccc;
struct student {
	int a; 
	int b ;
};
int main(void) 
{
	aaa.a = 100 ;
	aaa.b = 200 ; 
	//相同类型的结构体可以整体赋值
	abc = aaa ; //???
	//不同类型的结构体不可以整体赋值 
//	ccc = aaa ; 
	struct student bbb ;  //bbb.a = aaa.a ;
	struct student *tmp = NULL; 
	tmp = (struct student *)(&aaa) ; 
	bbb = *tmp ; 
	//不支持直接类型强转 
	//bbb = (struct student)aaa ; 
	printf("abc:%d  abc:%d \n" , abc.a , abc.b);
	printf("bbb:%d  bbb:%d \n" , bbb.a , bbb.b);
	return 0 ; 
}

