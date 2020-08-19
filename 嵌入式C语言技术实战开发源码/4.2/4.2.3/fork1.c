#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	pid_t pid = fork();
	if(pid<0)
	{
		return -1 ;
	}
	if(pid>0)
	{
		//父进程中打印子进程的PID
		printf("child pid is %d\n",pid);
		//父进程中打印父进程的PID
		printf("parent pid is %d\n",getpid());
	}
	else if(pid == 0)
	{
		//子进程中打印子进程的PID
		printf("child pid is %d\n ",getpid());
		//子进程中打印父进程的PID
		printf("ppid is %d\n ",getppid());
	}
	return 0;
}

