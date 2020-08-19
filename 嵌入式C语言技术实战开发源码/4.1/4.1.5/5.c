#include <stdio.h>
#include <dirent.h>
#define PATH "/Users/lkq/my/book/4.1/4.1.5"

int main()
{
	DIR *dir = NULL;
	struct dirent *entry;
	//打开一个目录
	if((dir = opendir(PATH)) == NULL)
	{
		printf("opendir file!\n");
		return 1;
	}else{
		//如果打开成功就开始读取目录中的文件
		while(entry = readdir(dir))
		{
			printf("%s\n",entry->d_name);  //获取目录文件名
		}
	}
	//关闭目录
	closedir(dir);
	return 0;
}

