#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t  pid ;
	//子进程先退出，父进程没有回收子进程资源  
	//这就是僵尸进程  
	//僵尸进程不能被直接杀死，只能通过杀死父进程来终止僵尸进程  
	pid = fork();     
	if(pid == 0)  
	{  
		printf("i am parent ... \n");  
		printf("pid:%d ppid:%d \n" , getpid() , getppid());  
		return 0 ;   
	}
	while(1)  
		sleep(1);  
	return 0 ;   
}

