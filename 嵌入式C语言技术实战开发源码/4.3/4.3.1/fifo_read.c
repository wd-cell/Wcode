#include <stdio.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define P_FIFO  "txt"

int main()
{
	int ret;
	int fd;
	char buf[20];
	//打开有名管道
	//第一个参数为有名管道文件路径
	//第二个参数表明是以读取方式并以非阻塞方式打开有名管道
	//O_RDONLY读取模式
	//O_NONBLOCK非阻塞方式
	fd = open(P_FIFO,O_RDONLY);
	if(fd<0)
	{
		printf("open fail\n");
		return -1 ;
	}
	//循环读取有名管道
	while(1)
	{
		memset(buf,0,sizeof(buf));
		if(read(fd,buf,sizeof(buf)) == 0)
		{
			printf("nodata.\n");
		}
		else
		{
			printf("getdata:%s\n",buf);
			break;
		}
	}
	close(fd);
	return 0;
}

