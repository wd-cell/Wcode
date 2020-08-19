#include<stdio.h>
struct A{
  char   a;//4
  int    b;//1
  char   c;//1
};
typedef struct A A;

int main()
{
    A s;
    printf("%d\n",sizeof(s));
   return 0;
}

