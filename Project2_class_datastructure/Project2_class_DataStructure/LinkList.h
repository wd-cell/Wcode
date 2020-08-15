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
	LinkList();									//��ʼ��������
	~LinkList();
	int GetLength();							//��ȡ������ĳ���
	bool IsEmpty();								//�ж��Ƿ�Ϊ��
	void Creat();	                         // ��������
	void HeadInsertNode(int date);			 // ��ͷ������ָ����Ԫ��
	void EndInsertNode(int date);			 //��β������ָ��Ԫ��
	void IndexInsertNode(int n, int date);    //��ָ��λ�ú������Ԫ��
	void DeleteIndexNode(int n);                 //ɾ��ָ��λ�õ�Ԫ��
	void Reverse();                              //��ת����
	void Display();                              //��ʾ����
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
	cout << "�������ɹ���" << endl;
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
		cout << "����λ�ò���ȷ!" << endl;
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
		cout << "����Ϊ�գ����跭ת" << endl;
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
		cout << "����Ϊ�գ���Ԫ�ؿ�ɾ��" << endl;
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