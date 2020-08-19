#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int sock  = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in saddr;//server sockaddr
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");	
	//建立套接字连接
	connect(sock, (struct sockaddr *)&saddr, sizeof(saddr));
	char buf[20] = "hello socket\n";
	//发送数据到服务器
	send(sock, buf, strlen(buf), 0);
	close(sock);
	return 0;
}

