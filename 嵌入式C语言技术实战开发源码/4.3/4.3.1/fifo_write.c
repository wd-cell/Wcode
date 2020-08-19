#include <stdio.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define P_FIFO  "txt"

int main()
{
	int fd;
	//要写入有名管道的数据
	char buf[20] = "hello write_fifo";
	int ret=0;
	//创建有名管道，并赋予访问有名管道的权限
	ret = mkfifo(P_FIFO,0777);
	//创建失败
	if(ret < 0)
	{
		printf("create named pipe failed.\n");
		return -1;
	}
	fd = open(P_FIFO,O_WRONLY);
	if(fd < 0)
	{
		printf("open failed.\n");
		return -2;
	}
	//写入数据到有名管道
	//第一个参数为有名管道文件描述符
	//第二个参数为写入有名管道的数据
	//第三个参数为写入有名管道的数据长度
	write(fd,buf,sizeof(buf));
	//关闭有名管道
	close(fd);
	return 0;
}

