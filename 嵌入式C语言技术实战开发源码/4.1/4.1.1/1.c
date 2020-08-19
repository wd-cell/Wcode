#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_PATH "txt"  //此处为同在该.c文件下的相对路径
int main()
{
	 //打开文件 
	int fd = open(FILE_PATH, O_RDWR|O_CREAT , 0777); 
	if (fd < 0){                              
		printf("open error\n"); 
		return -1;
	}else{
	    printf("open success\n");
	}

	close(fd); //关闭文件
   	return 0;
}

