#include <stdio.h>  
int main(void)  
{  
    unsigned int  temp = 0x42 ;  
    unsigned int  high = (temp - temp % 0x10) / 0x10 ;  //将高四位分离
    unsigned int  low = temp % 0x10 ;               //将第四位分离
    printf("high:%u    low:%u\n",high , low) ;   
    return 0 ;    
}   

