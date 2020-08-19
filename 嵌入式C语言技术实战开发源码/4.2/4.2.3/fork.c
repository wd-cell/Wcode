#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	//创建一个进程
	pid_t pid = fork();	
	//父进程
	if( pid>0 )   
	{
		printf("in parent.\n");
	}
	//子进程
	else if(pid == 0) 	
	{
		printf("in child.\n");
	}
	return 0;
}

