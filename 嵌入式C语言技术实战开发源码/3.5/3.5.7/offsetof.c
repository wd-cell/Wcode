#include <stdio.h>
#define offsetof(TYPE,MEMBER) ((int) &((TYPE *)0)->MEMBER)
#pragma pack(4)
struct ptr
{
	char a ; 
	short b ; 
	int  c ; 
	double d ;
};
#pragma pack()
int main(void)
{
	struct ptr Pt ;
	printf("ptr:%d\n",sizeof(struct ptr));//16
	
	//相对地址偏移量 
	int offset = offsetof(struct ptr,a);  //0
	printf("offset:%d\n",offset);
	int offset1 = offsetof(struct ptr,b); //2
	printf("offset1:%d\n",offset1);
	int offset2 = offsetof(struct ptr,c); //4
	printf("offset2:%d\n",offset2);
	int offset3 = offsetof(struct ptr,d); //8
	printf("offset3:%d\n",offset3);
	return 0 ;
}

