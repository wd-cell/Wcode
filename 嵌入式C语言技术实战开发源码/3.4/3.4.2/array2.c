#include<stdio.h>
int main()
{
  int a[3][3] = {{1,[2]=3},{2,[2]=6},{3,[2]=9}} ;
  int i , j ;
  for(i=0;i<2;i++)
  {
    for(j=0;j<3;j++)
    {
        printf("%d ",a[i][j]);
    }
       printf("\n");
  }
  return 0;
}

