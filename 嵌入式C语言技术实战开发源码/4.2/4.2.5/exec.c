#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	//以NULL结尾的字符串数组的指针，适合包含v的exec函数参数
	char *arg[] = {"ls", "-a", NULL};
	/**
	 * 创建子进程并调用函数execl
	 * execl 中希望接收以逗号分隔的参数列表，并以NULL指针为结束标志
	 */
	if( fork() == 0 )
	{
		printf( "1、execl：\n" );
		if( execl( "/bin/ls", "ls","-a", NULL ) == -1 )
		{
			perror( "execl error " );
			exit(1);
		}
	}
	/**
	 *创建子进程并调用函数execv
	 *execv中希望接收一个以NULL结尾的字符串数组的指针
	 */
	if( fork() == 0 )
	{
		printf("2、execv：\n");
		if( execv( "/bin/ls",arg) < 0)
		{
			perror("execv error ");
			exit(1);
		}
	}
	/**
	 *创建子进程并调用 execlp
	 *execlp中
	 *l希望接收以逗号分隔的参数列表，列表以NULL指针作为结束标志
	 *p是一个以NULL结尾的字符串数组指针，函数可以DOS的PATH变量查找子程序文
	 */
	if( fork() == 0 )
	{
		printf("4、execvp：\n");
		if( execvp( "ls", arg ) < 0 )
		{
			perror( "execvp error " );
			exit( 1 );
		}
	}
	/**
	 *创建子进程并调用execle
	 *l 希望接收以逗号分隔的参数列表，列表以NULL指针作为结束标志
	 *e 函数传递指定参数envp，允许改变子进程的环境，无后缀e时，子进程使用当前程序的环境
	 */
	if( fork() == 0 )
	{
		printf("5、execle：\n");
		if( execle("/bin/ls", "ls", "-a", NULL, NULL) == -1 )
		{
			perror("execle error ");
			exit(1);
		}
	}

	/**
	 *创建子进程并调用execve
	 * v 希望接收到一个以NULL结尾的字符串数组的指针
	 * e 函数传递指定参数envp，允许改变子进程的环境，无后缀e时，子进程使用当前程序的环境
	 */
	if( fork() == 0 )
	{
		printf("6、execve：\n");
		if( execve( "/bin/ls", arg, NULL ) == 0)
		{
			perror("execve error ");
			exit(1);
		}
	}
	return 0;
}

