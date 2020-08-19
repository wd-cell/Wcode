#include <stdio.h>  
int RecordBuffer[10];  
int buffer_write(unsigned int *buffer , int size_to_write) ;  
int main(void)  
{  
    unsigned int buffer[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09 ,0x0a};  
    buffer_write(buffer , 10);  
    int i ;  
    for(i = 0 ; i < 10 ; i++)   
        printf("Recordbuffer[%d]:%x\n",i , RecordBuffer[i]);  
    return 0 ;  
}  
  
int buffer_write(unsigned int *buffer , int size_to_write)  
{  
    int *p = (int *)buffer ;  
int i ;  
//合并
    for(i = 0 ; i < size_to_write ;i += 2)  
        RecordBuffer[i/2] = *(p+i)|(*(p+i+1) << 8) ;  
}  

