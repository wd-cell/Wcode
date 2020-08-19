#include <stdio.h>  
#include <stdarg.h>  
/*  
可变参相关接口  
typedef char * va_list ;  
void va_start (va_list ap , prev_param) ; 
type va_arg(va_list ap , type) ; 
void va_end(va_list ap);  
*/  
int myfprintf(FILE* fp, char* fmt, ...)  
{  
     int ret = 0;   
     va_list args;  //va_list是一个字符串指针，用于获取不确定个数的参数   
     va_start(args,fmt); //读取可变参数的过程其实就是在堆栈中，使用指针，遍历堆栈段中  
     //的参数列表，从低地址到高地址一个一个的把参数内容读出来的过程   
       
     //该函数会根据参数fmt字符串来转换格式并格式化数据，然后将结果输出到参数Stream指定的文件中  
     //直到出现字符串结束的\0为止。   
     ret = vfprintf(fp, fmt, args);  
     //获取完所有参数之后，为了避免发生程序瘫痪，需要将 ap指针关闭，其实这个函数相当于将args设置为NULL   
     va_end(args);  
     return ret;  
}  
  
int main(void)  
{  
    myfprintf(stdout,"hello world\n");  
    return 0 ;  
}  

