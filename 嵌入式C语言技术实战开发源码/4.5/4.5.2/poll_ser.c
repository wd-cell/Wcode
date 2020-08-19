#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#define __USE_GNU
#include <poll.h>	

#define MAX_USER 50
#define BUFSIZE 100

int main()
{
	int i = 0, j = 0;
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = INADDR_ANY;
	
	int len = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &len, sizeof(len));
	
	int ret = bind(sock, (struct sockaddr *)&saddr, sizeof(saddr));
	if( ret!= 0){
		printf("bind error\n");
		exit(-1);
	}
	listen(sock, 5);
	struct pollfd fds[MAX_USER];
	for(i=0; i<MAX_USER; i++){
		fds[i].fd = -1;
		fds[i].events = 0;
		fds[i].revents = 0;
	}
	fds[0].fd = sock;
	fds[0].events = POLLIN;
	fds[0].revents = 0;
	int count = 0;
	
	char buf[BUFSIZE] = {0};
	while(1){
		int ret = poll(fds, count+1, -1);
		for(i=0; i<count+1; i++){
			if( (fds[i].revents&POLLIN)&&(fds[i].fd == sock)){
				struct sockaddr_in caddr;
				int len = sizeof(caddr);
				int fd = accept(sock, (struct sockaddr *)&caddr, &len);
				if( fd>0 ){
					printf("client connect\n");
				}else{
					printf("connet error\n");
					//exit(-1);
					continue;
				}
				count++;
				fds[count].fd = fd;
				fds[count].events = POLLIN|POLLRDHUP;
				fds[count].revents = 0;
				printf("client sum is %d\n", count);
			}else if( fds[i].revents & POLLRDHUP ){
				close(fds[i].fd);
				fds[i] = fds[count];
				count--;
				i--;
				printf("client exit\n");
			}else if( fds[i].revents & POLLIN ){
				memset(buf, 0, BUFSIZE);
				int ret = read(fds[i].fd, buf ,BUFSIZE);
				if( ret>0 ){
					for(j=1; j<count+1; j++){
						if( fds[j].fd == fds[i].fd){
							continue;
						}
						write(fds[j].fd, buf, ret);
					}
				}
			}
		}
	}
	close(sock);
	return 0;
}

