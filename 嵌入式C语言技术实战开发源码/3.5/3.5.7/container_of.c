#include <stdio.h>  
#include <stdlib.h>
//获取结构体成员相对于结构体的偏移 
#define offsetof(TYPE,MEMBER) ((int) &((TYPE *)0)->MEMBER)  
//通过获取结构体中的某个成员的，反推该结构体的指针 
#define container_of(ptr, type , member) ({ \
	const typeof(((type *)0)->member) *__mptr = (ptr) ; \
	(type *)((char *)__mptr - offsetof(type,member)) ;})

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
    struct ptr *pt ;
    printf("ptr:%d\n",sizeof(struct ptr));//16  
    //获取结构体的首地址 
    printf("ptr:%p\n",&Pt); //0028FEA8
    Pt.a = 'a';
    Pt.b = 2 ;
    Pt.c = 4 ;
    Pt.d = 12.04 ;
    //通过container_of获取结构体的首地址 
    pt = container_of(&Pt.c, struct ptr , c);
    printf("pt:%p\n",pt);  //0028FEA8
    printf("a:%c\n",pt->a) ;  //'a'
    printf("b:%d\n",pt->b) ;  //2
    printf("c:%d\n",pt->c) ;  //4
    printf("d:%.2lf\n",pt->d);//12.04
    return 0 ;  
}  

