#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define __USE_GNU
#include <poll.h>
#include <string.h>

int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	connect(sock, (struct sockaddr *)&saddr, sizeof(saddr));
	
	struct pollfd fds[2];
	fds[0].fd = 0;//STDIN_FILENO
	fds[0].events = POLLIN;
	fds[0].revents = 0;
	fds[1].fd = sock;
	fds[1].events = POLLIN|POLLRDHUP;
	fds[1].revents = 0;
	
	char rbuf[30] = {0};
	char buf[30] = {0};
	while(1){
		int ret = poll(fds, 2, -1);
		if( fds[0].revents & POLLIN ){
			memset(rbuf, 0, 30);
			int ret = read(0, rbuf, sizeof(rbuf));
			write(sock, rbuf, ret);
			ret = 0;
		}
		if( fds[1].revents & POLLRDHUP ){
			printf("server exit\n");
			break;
		}else if( fds[1].revents & POLLIN ){
			memset(buf, 0, 30);
			int ret = read(sock, buf ,sizeof(buf));	
			write(1, buf, ret);
			ret = 0;
		}
	}	
	close(sock);
	return 0;
}

