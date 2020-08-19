#include <stdio.h>
struct student
{
	char a ; 
	double b ; 
};
int main(void)
{
	printf("size:%d \n" , sizeof(struct student));
	return 0 ; 
}

