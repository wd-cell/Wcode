#include <stdio.h>
//打印二维数组
void pri(int c[][3],int n)   
{
   int i=0,j=0;
     for(i=0;i<n;i++)
     {
       for(j=0;j<3;j++)
       {
          printf("%d ",c[i][j]);
       }
       printf("\n");
     }
}
int main()
{
   int c[2][3]={{1,2,3},{4,5,6}};
   pri(c,2);
   return 0;
}

