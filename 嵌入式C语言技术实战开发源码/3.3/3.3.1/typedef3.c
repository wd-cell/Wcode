#include <stdio.h>  
#include <stdlib.h>  
typedef struct tree  
{  
    int number ;   
    struct tree *left  ;   
    struct tree *right ;   
}TREE;  
//对树插入节点   
void insert_tree(TREE **header , int number)  
{  
    //创建一颗树   
    TREE *New = NULL ;   
    New = malloc(sizeof(TREE));  
    if(NULL == New)  
       return ;  
    //初始化树节点的值   
    New->number = number ;   
    //分别将左子树和右子树设置为空   
    New->left = NULL ;   
    New->right = NULL ;   
    TREE **link = header ;   
    TREE *cur ;   
    while(cur = *link)  
    {   
        //判断新插入的节点和之前的值之间谁大谁小  
        //小的就放在左子树，大的就放到右子树   
        if(New->number < cur->number)  
            //*link = cur->left ;   
            link = &(cur->left) ;  
        else  
            link = &(cur->right) ;   
    }  
    *link = New ;  
}  
//打印树   
void print_tree(TREE *header , int lever)  
{  
    if(header == NULL)  
        return ;   
      
    print_tree(header->right , lever+1);  
    int i ;   
    for(i = 0 ; i < lever ; i++)  
        printf("\t");  
    printf("%d\n" , header->number);  
  
    print_tree(header->left , lever+1);  
}  
//树的前序遍历   
void front(TREE *header)  
{  
    if(header == NULL)  
        return ;   
    printf("%d " , header->number);  
    front(header->left);  
    front(header->right);  
}  
//树的中序遍历   
void middle(TREE *header)  
{  
    if(header == NULL)  
        return ;   
    middle(header->left);  
    printf("%d " , header->number);  
    middle(header->right);  
}  
//树的后序遍历   
void back(TREE *header)  
{  
    if(header == NULL)  
        return ;   
    back(header->left);  
    back(header->right);  
    printf("%d " , header->number);  
}
int main(void)  
{  
    int i ;   
    int buffer[10] ;  
    TREE *header = NULL ;  
    for(i = 0 ; i < 10 ; i++)  
    {  
        buffer[i] = rand()%100 ;  
    }  
    for(i = 0 ; i < 10 ; i++)  
    {  
        //给树插入元素   
        insert_tree(&header , buffer[i]);  
    }  
    print_tree(header , 1);  
    printf("\n前序遍历\n");  
    front(header);  
    printf("\n中序遍历\n");  
    middle(header);  
    printf("\n后序遍历\n");  
    back(header);  
    getchar();  
} 

