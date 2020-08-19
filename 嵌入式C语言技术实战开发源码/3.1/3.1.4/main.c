#include <stdio.h>
#include <stdlib.h>
//BCD码转为二进制 
unsigned bcd2bin(unsigned char val)
{
	return (val & 0x0f) + (val >> 4) * 10;
}
//二进制转为BCD码 
unsigned char bin2bcd(unsigned val)
{
	return ((val / 10) << 4) + val % 10;
}
int main(void)
{
	unsigned  val =  17;
	printf("bin:%u--->0x%x\n",val,val);
	printf("bcd:%u--->0x%x\n",bin2bcd(val) , bin2bcd(val));
	return 0 ;
}

