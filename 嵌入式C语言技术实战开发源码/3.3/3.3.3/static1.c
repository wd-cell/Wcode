#include<stdio.h>  
void fun();  
int main()  
{  
  fun();  
  fun();  
  return 0;  
}  
  
void fun()  
{  
   static int a = 0;  
   a++ ;   
   printf("a:%d\n",a);  
}  

