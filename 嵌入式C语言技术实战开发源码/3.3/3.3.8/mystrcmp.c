#include <stdio.h>
int mystrcmp(const char *p1 , const char *p2);
int main(void)
{
	char *p1 = "helloo";
	char *p2 = "hello";
	if(mystrcmp(p1 , p2) == 0)
		printf("equal to ... \n");
	else if(mystrcmp(p1 , p2) > 0)
		printf("bigger than zero ... \n");
	else
		printf("smaller than zero ... \n");
	return 0 ;
}

int mystrcmp(const char *p1 , const char *p2)
{
	//遍历字符串中的每一个字符，判断是不是'\0' 
	while((*p1 != '\0') || (*p2 != '\0'))
	{
		//如果p1 > p2，返回1，表示p1比p2长 
		if(*p1 > *p2)	
			return 1 ; 
		//如果p1 < p2，返回-11，表示p2比p1长 
		if(*p1 < *p2)
			return -1 ; 
		//指针往后偏移 
		p1++ ; 
		p2++ ; 
	}
	return 0 ; 
}

