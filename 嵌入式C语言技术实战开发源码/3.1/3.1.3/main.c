#include <stdio.h>
typedef char TUINT8 ;
typedef int  TUINT32;
TUINT32 Read_DecNumber(const TUINT8* str);
TUINT32 Read_HexNumber(const TUINT8* str); 
int main(void)
{
	int ret = Read_DecNumber("1000");
	int d = Read_HexNumber("A");
	printf("将字符串中的数字转化为10进制数 :%d\n",ret);
	printf("将字符串中的16进制数转化为10进制数 :%d\n",d);
	return 0 ;
}
//将字符串中的数字转化为10进制数 
TUINT32 Read_DecNumber(const TUINT8* str){
    TUINT32 value;
    if (! str)
        return 0;
    value = 0;
    while ((*str >= '0') && (*str <= '9')){
        value = value*10 + (*str - '0');
        str++;
    }
    return value;
}
//将字符串中的16进制数转化为10进制数 
TUINT32 Read_HexNumber(const TUINT8* str)
{
    TUINT32 value;
    if (! str)
        return 0;
    value = 0;
    while (1)
{ 
        if ((*str >= '0') && (*str <= '9'))
            value = value*16 + (*str - '0');
        else if ((*str >= 'A') && (*str <= 'F'))
            value = value*16 + (*str - 'A') + 10;
        else if ((*str >= 'a') && (*str <= 'f'))
            value = value*16 + (*str - 'a') + 10;
        else
            break;      
str++;
    }
    return value;
}

