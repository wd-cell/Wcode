#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	//创建一个进程
	pid = fork();

	//创建进程失败
	if(pid < 0)
	{
		perror("fork error:");
		exit(1);
	}
	if(pid == 0)
	{
		printf("first child pid:%d, ppid:%d\n", getpid(), getppid());
		//沉睡5s，保证父进程先退出
		sleep(5);
		printf("second child pid:%d,ppid:%d\n", getpid(), getppid());
		while(1)
			wait(1);
		return 0;
	}
	sleep(1);
	printf("parent pid:%d, ppid:%d\n", getpid(), getppid());
	printf("I am die ... \n");
	return 0 ;
}

