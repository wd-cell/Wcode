#include <stdio.h>
//定义一个动物结构体
struct Animal
{
	//动物有id还有名字,动物会跑
	int id ;
	char *name;
	int (*can_run)(int , char *);
};
//定义一个描述狗的结构体
struct Dog
{
	//狗也是动物，拥有动物的特性
	struct Animal animal ; 
	//狗会叫
	int (*can_bray)(int , char *);	
};
//实现狗可以跑的方法
int Dog_can_run(int id , char *name)
{
	printf("id:%d-->I am %s , I can run\n",id,name);
	return 0 ;
}
//实现狗可以叫的方法
int Dog_can_bray(int id , char *name)
{
	printf("id:%d-->I am %s , I can bray\n",id,name);
	return 0 ;
}
int main(void)
{
	//定义一个描述狗的结构体变量
	struct Dog dog ;
	//给狗变量赋值,来自于动物结构体的中的属性值还有方法
	dog.animal.id = 100 ;
	dog.animal.name = "dog" ;
	dog.animal.can_run = Dog_can_run ;
	//狗结构体自己的方法
	dog.can_bray = Dog_can_bray ;
	dog.animal.can_run(dog.animal.id , dog.animal.name) ;
	dog.can_bray(dog.animal.id,dog.animal.name);
	return 0 ;	
}

