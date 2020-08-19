#include<stdio.h>
int main()
{
  int a[2][3]={{1,2,3},{4,5,6}};
  int i , j ;
  for(i=0;i<2;i++)
  {
    for(j=0;j<3;j++)
    {
        printf("%d ",a[i][j]);
}
   //按行输出
        printf("\n");
  }
  return 0;
}

