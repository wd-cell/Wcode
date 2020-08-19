#include <stdio.h>    
int test_bit(int num)  
{  
    int i ;   
    for(i = 7 ; i >= 0 ; i--)  
    {  
        if(num & (1 << i))  
            printf ("3000hz\n") ;   
        else   
            printf ("1000hz\n") ;   
    }  
}  
int main(void)    
{    
    test_bit(0xfd) ;    
}  

