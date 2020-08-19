#include <stdio.h>
//#define  带参时的状况
#define  NR(x)     (sizeof(x)/sizeof(x[0]+0))
#define  msleep(x) (usleep(x*1000))
//#define  PP(x)     printf("我其实不想说这句话:" #x "\n")
#define  PP1(x)     printf("我其实不想说这句话:" #x "\n")
#define  PP2(x)     printf("其实我很想说:" #x "\n")
#define  PP3(x)     printf("你不说我也会说:" #x "\n")
#define  PP4(x)     printf("你不说我也知道:" #x "\n")
//#    将一串数据转成字符串    字符串转义
//##   字符串粘贴
//将PP粘贴成PP1
#define  XP(num , array)   PP##num(array);
int main(void)
{
	//字符串的自动粘贴功能
	//只要字符串放在一块会自动粘贴
	printf("hello"" ""world%d ""\n" , 100);
//	PP(你不错);
	XP(2,我不知道)
	return 0 ; 
}

