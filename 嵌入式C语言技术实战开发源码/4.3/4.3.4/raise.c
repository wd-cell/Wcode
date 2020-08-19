#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int ret;
	if((pid=fork())<0)
	{
		printf("Fork error\n");
		exit(1);
	}
	//子进程
	if(pid==0)
	{
		//在子进程中使用raise()函数发出SIGSTOP信号，使子进程暂停
		printf("I am child pid:%d.I am waiting for any signal\n",getpid());
		raise(SIGSTOP);
		printf("I am child pid:%d.I am killed by progress:%d\n",getpid(),getppid());
		exit(0);
	}
	//父进程
	else  
	{
		sleep(2);  
		//在父进程中收集子进程发出的信号，并调用kill()函数进行相应的操作
		if((waitpid(pid,NULL,WNOHANG))==0) 
		{ 
			//若pid指向的子进程没有退出，则返回0,且父进程不阻塞,继续执行下边的语句
			if((ret=kill(pid,SIGKILL))==0)
			{
				printf("I am parent pid:%d.I am kill %d\n",getpid(),pid);
			}
		}
		//等待子进程退出，否则就一直阻塞
		waitpid(pid,NULL,0);
		exit(0);
	}
}

