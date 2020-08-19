#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
	
int main(void)
{
	int msgid ;

	msgid = msgget(0x123456 , 0);
	if(msgid == -1)
	{
		perror("create msg queue fail");
		return -1 ;
	}
	printf("open msg success ... \n");
	int ret ;
	char *p = "hello world" ;
	//发送hello world到消息队列0x123456
	//在这里可以直接发送
	ret = msgsnd(msgid , p , strlen(p) , 0);
	if(ret == -1)
	{
		perror("send msgid fail");
		return -2 ;
	}
	return 0 ;
}

