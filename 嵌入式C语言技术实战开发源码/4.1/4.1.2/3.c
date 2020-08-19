#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FILE_PATH "txt" 
int main()
{
	char *data = malloc(100);
	int fd = open(FILE_PATH, O_RDWR);
	if(fd < 0 ){
		printf("open error\n");
		return -1;
	}
	int ret = read(fd, data, 100);
	if(ret < 1){
		printf("read error");
		return -2;
	}
	printf("%s\n", data);
	free(data);
	close(fd);
	return 0;
}

