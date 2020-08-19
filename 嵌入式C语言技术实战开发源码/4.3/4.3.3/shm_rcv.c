#include <stdio.h>
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
	shmid = shmget(0x66, SHM_SIZE, IPC_CREAT|0666);
	if(shmid < 0)
	{
		perror("shmget");
		return -1 ;
	}
	shmptr = shmat(shmid, 0, 0);
	if (shmptr == (void *)-1)
	{
		perror("shmat");
		return -2 ;
	}
	// 从共享内存读数据   
	printf("read:%s\n", shmptr);
	shmdt(shmptr);
	return 0 ;
}

