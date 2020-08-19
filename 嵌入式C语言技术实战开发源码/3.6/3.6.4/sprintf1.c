#include<stdio.h>
int main()
{ 
 	double a=123.123;
    char buf[32]={0};
    sprintf(buf,"%lf",a);
    printf("%s\n",buf);
  return 0;
}

