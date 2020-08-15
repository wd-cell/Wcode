#pragma once
#include <iostream>
using namespace std;

typedef struct node
{
	int date;
	struct node *next;
}Node;

class LinkList
{
private:
	Node *head;
public:
	LinkList();									//初始化单链表
	~LinkList();
	int GetLength();							//获取单链表的长度
	bool IsEmpty();								//判断是否为空
	void Creat();	                         // 创建链表
	void HeadInsertNode(int date);			 // 从头部插入指定的元素
	void EndInsertNode(int date);			 //从尾部插入指定元素
	void IndexInsertNode(int n, int date);    //从指定位置后面插入元素
	void DeleteIndexNode(int n);                 //删除指定位置的元素
	void Reverse();                              //反转链表
	void Display();                              //显示链表
};

LinkList::LinkList()
{
	Node *tmp = new Node;
	head = tmp;
}
LinkList::~LinkList()
{
	Node *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}
bool LinkList::IsEmpty()
{
	if (head->next == NULL) return true;
	return false;
}

int LinkList::GetLength()
{
	int length = 0;
	Node *p = head->next;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}

void LinkList::Creat()
{
	Node *p, *s;
	int x, cycle = 1;
	p = head;
	while (cycle)
	{
		cout << "please inpur a number:" << endl;
		cin >> x;
		if (x != 0)
		{
			s = new Node;
			s->date = x;
			p->next = s;
			p = s;
		}
		else
			cycle = 0;
	}
	//head = head->next;
	p->next = NULL;
	cout << "链表建立成功！" << endl;
}

void LinkList::HeadInsertNode(int date)
{
	Node *p1 = new Node;
	p1->date = date;
	p1->next = head->next;
	head->next = p1;
}

void LinkList::IndexInsertNode(int n, int date)
{
	Node *p = head->next;
	int count = 0;
	int length = GetLength();
	if (n <= 0 || length < n)
		cout << "插入位置不正确!" << endl;
	while (p != NULL)
	{
		count++;
		if (count == n)
		{
			node *p1 = new Node;
			p1->date = date;
			p1->next = p->next;
			p->next = p1;
		}
		p = p->next;
	}
}

void LinkList::EndInsertNode(int date)
{
	Node *p = head->next;
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			Node *p1 = new Node;
			p1->date = date;
			p1->next = NULL;
			p->next = p1;
			break;
		}
		p = p->next;
	}
}

void LinkList::Reverse()
{
	if (head->next == NULL)
	{
		cout << "链表为空，无需翻转" << endl;
		exit(0);
	}
	Node *p1, *p2, *p3;
	p1 = head; p2 = head->next;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next->next = NULL;
	head->next = p1;
}

void LinkList::Display()
{
	Node *p = head->next;
	while (p != NULL)
	{
		cout << p->date << " ";
		p = p->next;
	}
	cout << endl;
}

void LinkList::DeleteIndexNode(int n) {
	if (IsEmpty()) {
		cout << "链表为空，无元素可删！" << endl;
		return;
	}
	Node *p = head;
	while (p) {
		if (--n == 0) {
			Node *q = p->next;
			p->next = p->next->next;
			delete q;
			q = NULL;
			return;
		}
		p = p->next;
	}
	return;
}