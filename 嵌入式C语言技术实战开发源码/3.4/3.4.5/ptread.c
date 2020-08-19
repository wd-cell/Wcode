#include <stdio.h>
#include <pthread.h>


void *function(void *args)
{
	while(1)
	{
		printf("hello world1!\n");
		sleep(1);
	}
}
int main(void)
{
	pthread_t tid ;
	tid = pthread_create(&tid , NULL , function , NULL);
	while(1)
	{
		printf("hello world!\n");
		sleep(1);
	}
	return 0 ;
}

