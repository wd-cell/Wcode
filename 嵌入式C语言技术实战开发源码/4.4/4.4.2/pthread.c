#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *thread_1(void *arg)
{
	printf("thread one\n");
}
void *thread_2(void *arg)
{
	printf("thread two\n");
}
int main()
{
	int ret = 0;
	pthread_t pid = 0;
	pthread_t pid1 = 0;
	//创建线程1
	ret = pthread_create(&pid, NULL, thread_1, NULL);
	if(ret < 0)
	{
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	//创建线程2
	ret = pthread_create(&pid1, NULL, thread_2, NULL);
	if(ret < 0)
	{
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	//等待线程退出
	pthread_join(pid, NULL);
	pthread_join(pid1, NULL);
	return 0;
}

