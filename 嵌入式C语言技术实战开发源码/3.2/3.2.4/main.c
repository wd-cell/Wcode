#include <stdio.h>
unsigned char reverse_bits(unsigned char value)  
{  
    unsigned char answer , i ;   
    answer = 0 ;  
    for(i = 1 ; i != 0 ; i <<= 1)  
    {  
        answer <<= 1 ;   
        if(value & 1)  
            answer |= 1 ;   
        value >>= 1 ;       
    }      
    return answer ;  
}  
int main(void)
{
	//0xef---->1110 1111
	unsigned char value = 0xef ;
	//翻转位变成---> 1111 0111 ---> 0xf7 
	unsigned char ret = reverse_bits(value);
	printf("0x%x\n",ret);
	return 0 ;
}

