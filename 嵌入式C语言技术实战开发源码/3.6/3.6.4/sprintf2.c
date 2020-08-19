#include<stdio.h>
#define  FILE_NAME  "test.txt"
int main()
{ 
	char name[10] = {0} ;
	sprintf(name,"%s",FILE_NAME);
	FILE *filp = fopen(name,"r+");
	if(NULL == filp){
		printf("open fair!\n");
		return -1 ;
	}
	fseek(filp,0,SEEK_SET);
	int data[11] = {0};
	int len = fread(data,11,1,filp);
	if(len < 0){
		printf("read fair!\n");
		return -2 ;
	}
	data[11] = '\0';
	printf("data:%s\n",data);
   return 0;
}

