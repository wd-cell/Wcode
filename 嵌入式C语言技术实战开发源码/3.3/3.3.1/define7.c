#include <stdio.h>
//错误号    所对应的错误信息
#define    ERRMSG1               "打开文件出错"
#define    ERRMSG2				 "打开数据库出错"
#define    ERRMSG3				 "连接服务器出错"
#define    ERRMSG4				 "连接数据库出错"
//错误级别-----结合可变参
#define    ERROR1(errno , ...)    fprintf(stderr , "严重错误: "ERRMSG##errno"  " __VA_ARGS__);
#define    ERROR2(errno , ...)    fprintf(stderr , "错误: "ERRMSG##errno"  " __VA_ARGS__);
#define    ERROR3(errno , ...)    fprintf(stdout , "警告: "ERRMSG##errno"  " __VA_ARGS__);
#define    ERROR4(errno , ...)    fprintf(stdout , "提示: "ERRMSG##errno"  " __VA_ARGS__);
#define    ERROR5(errno , ...)    fprintf(stderr , "系统错误: "ERRMSG##errno"  " __VA_ARGS__);
//定义错误函数
#define  ERR(lever , errno , con , todo , ...)				\
		 do									\
		 {									\
			if(con)							\
			{								\
				ERROR##lever(errno,__VA_ARGS__)				\
				todo;										\
			}								\
		 }while(0);

int main(void)
{
	int a = -1 ; 
	ERR(1 , 1 , a < 0 , goto err , "错误号:%d 不小心在%d时间里报的错误\n" ,1, 22);
	return 0 ; 
	err:
	return -1 ; 
}

