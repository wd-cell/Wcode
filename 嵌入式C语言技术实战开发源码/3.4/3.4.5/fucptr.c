#include <stdio.h>
void print();
int main(void)
{
	void (*fuc)(); 
	fuc = print ; 
	fuc(); 	
} 
void print()
{
	printf("hello world!\n");
}

