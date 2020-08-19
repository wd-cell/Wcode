#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FILE_PATH "txt"
int main()
{
	char *data = "hello file";
	int fd = open(FILE_PATH, O_RDWR|O_APPEND); 
	if(fd < 0 ){
		     printf("open error\n");
			      return -1;
	}
	int ret = write(fd, data, 10);  //将data写入文件中
	if(ret < 1){
		     printf("write error");
			      return -2;
	}
	printf("write success!\n");
	close(fd);
	return 0;
}

