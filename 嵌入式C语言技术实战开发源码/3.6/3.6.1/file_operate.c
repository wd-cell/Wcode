#include<stdio.h>
int main()
{
   //以可读可写的方式打开文件 
   FILE* fp=fopen("text.txt","r+");
      if(fp==NULL)
      {
         printf("fopen err:%m\n");
         return -1;
      }

   printf("文件打开成功 :%p\n",fp);
  fclose(fp);//关闭文件
  return 0;
}

