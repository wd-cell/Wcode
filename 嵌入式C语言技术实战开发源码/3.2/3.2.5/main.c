#include <stdio.h>    
void delay()  
{  
    int i , j ;   
    for(i = 0 ; i < 1000 ; i++)  
        for(j = 0 ; j < 8000 ;j++);  
}  
//跑马灯从高位到低位流  
void test_low_to_high_bit()  
{  
    int i , j ;   
    int tick ;  
    static int ledbuf[10] ;  
    for(i = 0 ; i < 10 ; i++)  
    {  
    	//设定每次开始的位置，从0x01开始 
        ledbuf[i] = 0x01 ;  
        for(j = 0 ; j < 8 ; j++)  
        {  
            printf("%p ",ledbuf[i]); 
			//每次左移一位，左移八次 
            ledbuf[i] <<= 1 ;   
            delay() ;  
        }  
        putchar('\n');
		//将数组清0，等待进入下一行   
        ledbuf[i] = 0 ;  
    }  
}  
//跑马灯从低位到高位流  
void test_high_to_low_bit()  
{  
    int i , j ;   
    int tick ;  
    static int ledbuf[10] ;  
    for(i = 0 ; i < 10 ; i++)  
    {  
    	//设定从高位的第一个LED灯的位置  
        ledbuf[i] = 0x80 ;  
        for(j = 0 ; j < 8 ; j++)  
        {  
            printf("%p ",ledbuf[i]);  
            //将数组的第一个元素右移一位,一共右移八位 
            ledbuf[i] >>= 1 ;  
            delay() ;  
        }  
        putchar('\n');  
        //将数组清0，等待进入下一行
        ledbuf[i] = 0 ;
    }  
}  
int main(void)  
{  
    test_low_to_high_bit() ;  
    putchar('\n');  
    test_high_to_low_bit() ;    
    return 0 ;  
}  

