#include <stdio.h>
struct student 
{
	char name[20] ; 
	int age ; 
	int id  ;
	//在结构体中内嵌函数指针 
	void (*introduce)(const char *name , int age , int id) ; 
};
//定义给结构体中函数指针赋值的函数
void say_tom(const char *name , int age , int id);
void say_dog(const char *name , int age , int id);
//初始化结构体
struct student  Mery = {
	.name = "Mery",
	.age = 19 ,
	.id  = 100 ,
	.introduce = say_tom,
};
int main(void)
{
	struct student Tom = {"Tom" ,  18 , 99 , say_dog};
	Tom.introduce(Tom.name , Tom.age , Tom.id);
	Mery.introduce(Mery.name , Mery.age , Mery.id);
	return 0 ; 
}
void say_tom(const char *name , int age , int id)
{
	printf("my name is %s i am a good boy age:%d myid is:%d \n" , 
	name , age , id);
}
void say_dog(const char *name , int age , int id)
{
	printf("my name is %s i am a dog age:%d myid is:%d \n" , 
	name , age , id);
}

