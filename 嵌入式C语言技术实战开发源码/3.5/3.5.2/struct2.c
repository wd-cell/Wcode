#include <stdio.h>
#pragma  pack(1)
struct student
{
	char a ; 
	double b ; 
};
#pragma  pack()

int main(void)
{
	printf("size:%d \n" , sizeof(struct student));
	return 0 ; 
}

