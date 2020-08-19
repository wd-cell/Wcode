#include <stdio.h>
int main(void)
{
	//int a ==> auto signed int a ; 
	int   a = 200 ; 
	printf("a:%d \n" , sizeof(a));	
	unsigned int b = 200 ; 
	printf("b:%d \n" , sizeof(b));
	short int c = 200 ; 
	printf("c:%d \n" , sizeof(c));
	long int  d = 200 ;
printf("longint:%d   longlong:%d  \n" , sizeof(long int) , sizeof(long long));
	printf("d:%d \n" , sizeof(d));
	long long e = 200 ; 
	printf("e:%d \n" , sizeof(e));
	char ch = 'a' ;  
	printf("ch:%d\n" , sizeof(ch));
	char *p = "hello world" ;   
	printf("p:%d \n" , sizeof(p));
	float  f = 0.7 ; 
	printf("f:%d \n" , sizeof(f));
	double db = 0.783 ; 
	printf("db:%d \n" , sizeof(db));
	return 0 ; 
}

