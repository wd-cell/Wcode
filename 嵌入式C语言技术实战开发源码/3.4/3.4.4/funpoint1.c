#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define abs(a,b) a < b ?(b-a):(a-b) //定义一个绝对值宏
int add(int a , int b)
{
	return a+=b;
}
int sub(int a , int b)
{
	return a-=b;
}
int time(int a , int b)
{
	return a*=b ;
}
int main(int argc, char *argv[])
{
	int a = 20 , b = 10 ;
	int (*addfun)(int , int) = add;
	int (*timefun)(int , int) = time ;
	int (*subfun)(int , int) = sub ;
	int offset = subfun-addfun ;
	int (*fpofset)(int , int) = subfun-offset;
	printf("%p--->%d\n",fpofset,fpofset(a,b));
	int offs = abs(addfun,timefun);
	int (*ftimefset)(int , int) = fpofset+offs;
	printf("%p---> %d\n",ftimefset,ftimefset(a,b));
	int *p = (int *)add ;
	int (*q)(int,int) = p ;
	printf("%d\n",q(a,b));
	return 0;
}

