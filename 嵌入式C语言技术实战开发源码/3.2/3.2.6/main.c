#include <stdio.h>  
void pri() ;   
void pri1() ;  
int play_sound_lowtohigh(unsigned int num) ;  
int bit0o1(int it,int position) ;  
int play_sound_hightolow(unsigned int num) ;
int  main()   
{  
    unsigned int num = 0xfd ; //1111 1101  
    play_sound_lowtohigh(num);  
    putchar('\n');  
    play_sound_hightolow(num);  
          
return   0;     
}  
//从低位往高位   
int play_sound_lowtohigh(unsigned int num)  
{  
    int i   = 0;  
    int bit = 0 ;  
    for(i = 1 ; i < 9 ; i++)  
    {  
        bit = bit0o1(num,i);  
        if(bit == 0)  
            pri();  
        else if(bit == 1)  
            pri1() ;  
    }         
}  
//从高位往低位   
int play_sound_hightolow(unsigned int num)  
{  
    int i   = 0;  
    int bit = 0 ;  
    for(i = 8 ; i > 0 ; i--)  
    {  
        bit = bit0o1(num,i);  
        if(bit == 0)  
            pri();  
        else if(bit == 1)  
            pri1() ;  
    }         
}  
//it 表示数据  
//position 表示第几位   
int bit0o1(int it,int position)  
{  
    int oc=1;  
    oc<<=(position-1);  
    return (oc&it)!=0?1:0;  
}  
  
void pri()  
{  
    printf("1000hz\n") ;   
}  
  
void pri1()  
{  
    printf("3000hz\n") ;  
}  

