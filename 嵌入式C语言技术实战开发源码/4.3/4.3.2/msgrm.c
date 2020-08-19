#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void)
{
	int  msgid ;
	msgid = msgget(0x123456 , 0);
	if(msgid < 0)
	{
		perror("msgget fail");
		return -1 ;
	}

	printf("success ... ! msgid:%d \n" , msgid);
	//写IPC_RMID标志
	if(msgctl(msgid , IPC_RMID , NULL) == 0)
	{
		printf("remove success ... \n");
	}
	return 0  ;
}

