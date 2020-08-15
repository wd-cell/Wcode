#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;

#define NULL 0
int const MAX_NUM = 20;
#define LEN sizeof(struct student)

struct student {
	char name[MAX_NUM];
	char sex[MAX_NUM];
	long int id;
	int score[4];
	int total;
	struct student *next;   //注意指针类别
};

static int n = 0;
class CInformation {
public:
	CInformation();
	virtual ~CInformation() {};
	student* creat();
	void output(student *head);
	int count(student *head);
	student* insert(student *head);
	student* cancel(student *head, long int num);
	student* find(student* head, long int num);
	void sort(student *head);
	void average(student *head);
	void save(student *head);
	student* Read();
private:
	student *p1, *p2,*p3, *head, st;
};