#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(void)
{
	int shmid ;
	//同样，首先先打开共享内存      
	shmid = shmget(0x66 , 0 , 0);
	if(-1 == shmid)
	{
		perror("open  shmkey 0x66 fail");
		return -1 ;
	}
	//成功话，向shmctl写入参数，IPC_RMID表示立刻删除，后面的参数被忽略，为0
	int ret ;
	//写入的是参数
	ret = shmctl(shmid , IPC_RMID , NULL);
	if(ret < 0)
	{
		perror("remove shm fail");
		return -2 ;
	}
	printf("remove key:%d success ... \n" , 0x66);
	return 0 ;
}

