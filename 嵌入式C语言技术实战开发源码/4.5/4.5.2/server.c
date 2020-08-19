#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

int main()
{
	int ret;
	//创建套接字
	int sock  = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in saddr;//server sockaddr
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");	
	//指定本地地址
	ret = bind( sock, (struct sockaddr *)&saddr, sizeof(saddr));
	if(ret < 0)
	{
		printf("bind fail\n");
		exit(1);
	}
	//监听连接
	listen(sock, 5);
	struct sockaddr_in cli;
	int len = sizeof(cli);
	//建立套接字连接
	int socklis = accept(sock, (struct sockaddr *)&cli, &len); 
	char buf[20] = {0};
	//接收由客户端发送来的数据
	recv(socklis, buf, 20, 0);
	printf("buf is %s\n", buf); 
	close(sock);
	close(socklis);
	return 0;
}

