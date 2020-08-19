#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//定义一个互斥锁变量
pthread_mutex_t m;
void *thread_1(void *arg)
{
	//互斥锁加锁
	pthread_mutex_lock(&m);
	printf("thread one\n");
	//互斥锁解锁
	pthread_mutex_unlock(&m);
}
void *thread_2(void *arg)
{
	pthread_mutex_lock(&m);
	printf("thread two\n");
	pthread_mutex_unlock(&m);
}	
int main()
{
	int ret = 0;
	//以动态方式创建互斥锁
	ret = pthread_mutex_init(&m, NULL);
	if(ret < 0)
	{
		perror("pthread_mutex_init");
		exit(EXIT_FAILURE);
	}
	pthread_t pid = 0;
	pthread_t pid1 = 0;
	ret = pthread_create(&pid, NULL, thread_1, NULL);
	if(ret < 0)
	{
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	ret = pthread_create(&pid1, NULL, thread_2, NULL);
	if(ret < 0)
	{
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	pthread_join(pid, NULL);
	pthread_join(pid1, NULL);
	return 0;
}

