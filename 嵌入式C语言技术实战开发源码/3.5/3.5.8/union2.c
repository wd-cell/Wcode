#include <stdio.h>
union port_output
{
	int a;
	char b;
};

int small_port(void)     
{
	union port_output o1;
	o1.a=1;
	return o1.b;
}

int main(void)
{
	int i = small_port();
	if(i == 1)
		printf("大端模式!\n");
	else 
		printf("小端模式!\n");
}

