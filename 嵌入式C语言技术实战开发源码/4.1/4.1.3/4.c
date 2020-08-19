#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FILE_PATH "txt"
int main()
{
	char *data = "test file"; 
	int fd = open(FILE_PATH, O_RDWR|O_APPEND);
	if(fd < 0 ){
		printf("open error\n");
		return -1;
	}
	//将该文件从文件开头偏移零位起始
	int chk = lseek(fd, 0, SEEK_SET);  
	if(chk < 0){
		printf("lseek error\n");
		return -2;
	}
	int ret = write(fd, data, 10);
	if(ret < 1){
		printf("write error\n");
		return -3;
	}
	printf("write success!\n");
	close(fd);
	return 0;
}

