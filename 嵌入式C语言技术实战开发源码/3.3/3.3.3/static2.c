#include <stdio.h>  
#include <stdlib.h>  
void delay(void)  
{  
    long int i = 0xffffff ;  
    while(i > 0)  
        i-- ;   
}   
  
void thread_work1(void)  
{  
    printf("任务一:\n");  
    delay();  
    static int type = 0;   
    static long int i = 5;  
    printf("i的值:%d\n",i) ;  
    switch(type)  
        {  
            case 0 :   
                   if(i > 0)  
                       i-- ;   
                   printf("type 0 :i=%d\n",i);  
                   type = 1 ;   
                   break ;   
            case 1 :   
                   if(i > 0)  
                    i-- ;  
                    printf("type 1 :i=%d\n",i);  
                   type = 0 ;  
                   break ;  
        }  
}  
void thread_work2(void)  
{  
    printf("任务二:\n");  
    delay();  
    static int type = 0 ;   
    static long int i = 5 ;  
    printf("i的值:%d\n",i) ;   
    switch(type)  
    {  
        case 0 :  
                if(i > 0)  
                    i-- ;  
                printf("type 0 :i=%d\n",i);  
                type = 1 ;  
                break ;  
        case 1 :  
                if(i > 0)  
                    i-- ;  
                printf("type 1 :i=%d\n",i);  
                type = 0 ;   
                break ;  
    }  
}  
void thread_work3(void)  
{  
    printf("任务三:\n");  
    delay();  
    static int type = 0 ;   
    static long int i = 5 ;   
    printf("i的值:%d\n",i) ;  
    switch(type)  
    {  
        case 0 :  
                if(i > 0)  
                    i-- ;  
                printf("type 0 :i=%d\n",i);  
                type = 1 ;  
                break ;  
        case 1 :  
                if(i > 0)  
                    i-- ;  
                printf("type 1 :i=%d\n",i);  
                type = 0 ;   
                break ;  
    }  
}  
int main(void)  
{  
    static int i = 3 ;  
    static int j ;  
    static int k ;  
    while(1)  
    {  
        printf("---------------第%d次调度开始-----------------\n",++j);  
        putchar('\n');  
        putchar('\n');  
        thread_work1();  
        thread_work2();  
        thread_work3();  
        putchar('\n');  
        putchar('\n');  
        printf("---------------第%d次调度完成-----------------\n",++k);  
        putchar('\n');  
        if(i > 0){  
            i-- ;  
            if(i == 0)  
                break;   
        }  
    }  
      
    return 0 ;  
}  

