#include <stdio.h>
//将一个8位数高低4位交换 
static inline unsigned char bswap_8(unsigned char v)
{
	//将参数(v & 0xff) << 4 相当于放到高位， v >> 4 位相当于放在低位
	return ((v & 0xff) << 4) | (v >> 4) ;  
}                      
//将一个16位数高低8位交换 
static inline unsigned short bswap_16(unsigned short v)
{
	return ((v & 0xff) << 8) | (v >> 8);
}
//将一个32位数高低16位交换 
static inline unsigned int bswap_32(unsigned int v)
{
	return ((v & 0xff) << 24) | ((v & 0xff00) << 8) |
		((v & 0xff0000) >> 8) | (v >> 24);
}
int main(void)
{
	unsigned short v = 0x1000 ;
	printf("1、\n原来的v:%d\n",v);
	printf("16位数高低8位转化后的v:%d(0x%x)==>0x%x--->%d\n",v,v ,bswap_16(v),bswap_16(v)) ;
	unsigned char  a = 0x0a  ;
	printf("\n2、\n原来的a:%d\n",a);
	printf("8位数高低4位转化后的a:%d(0x%x)==>0x%x--->%d\n",a,a ,bswap_8(a),bswap_8(a)) ;	
	unsigned int  b = 0x00001111; 
	printf("\n3、\n原来的b:%d\n",b);
	printf("32位数高低16位转化后的b:%d(0x%x)==>0x%x--->%d\n",b,b ,bswap_32(b),bswap_32(b)) ;
	return 0 ;
}

