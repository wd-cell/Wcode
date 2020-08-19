#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#define PATH "/Users/lkq/my/book/4.1/4.1.6/6.c"

int main()
{
	struct stat buf;
	stat(PATH,&buf);
							  
	printf("size = %lld\n",buf.st_size);
	return 0;
}

