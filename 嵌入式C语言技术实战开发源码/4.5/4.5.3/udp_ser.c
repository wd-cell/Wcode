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
	int sock  = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in saddr;//server sockaddr
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");	
	int loop = 1;
	//设置了recvfrom函数的超时机制，当loop设定的时间没有数据来到时recvfrom就会返回0.
	setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&loop,sizeof(loop));
	int s =bind( sock, (struct sockaddr *)&saddr, sizeof(saddr));
	if(s < 0)
	{
		perror("bind error");
	}
	
	char buf[20] = {0};
	struct sockaddr_in caddr;//client sockaddr
	int len = sizeof(caddr);
	recvfrom(sock, buf, 20, 0, (struct sockaddr *)&caddr, &len);
	printf("buf is %s\n", buf); 
	close(sock);
	return 0 ;
}
