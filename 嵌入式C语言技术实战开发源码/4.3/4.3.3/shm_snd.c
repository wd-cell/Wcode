#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024

int main()
{
	int shmid;
	char *shmptr;   
	//创建共享内存
	shmid = shmget(0x66, SHM_SIZE, IPC_CREAT|0666);
	//创建失败
	if(shmid < 0)
	{               
		perror("shmget");
		return -1 ;
	}
	//对共享内存的访问
	shmptr = shmat(shmid, 0, 0);
	if (shmptr == (void *)-1)
	{
		perror("shmat");
		return -2 ;
	}
	// 往共享内存写数据  
	strcpy(shmptr, "shmat write ok");
	shmdt(shmptr);
	return 0 ;
}

