#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void)
{
	int  msgid ; 
	//创建消息队列，注意，创建后面要有IPC_CREAT标志
	msgid = msgget(0x123456 , IPC_CREAT | 0777);
	if(msgid < 0)
	{
		perror("msgget fail");
		return -1 ; 
	}

	printf("success ... ! \n");
	return 0  ;
}

