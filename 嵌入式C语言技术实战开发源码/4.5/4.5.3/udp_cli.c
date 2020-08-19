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
	
	char buf[20] = "udp sendto ok\n";
	sendto(sock, buf, 20, 0, (struct sockaddr *)&saddr, sizeof(saddr));
	close(sock);
	return 0 ;
}

