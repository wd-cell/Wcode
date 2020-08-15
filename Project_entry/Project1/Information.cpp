#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include"Information.h"
#define ADRESS1 ("F:\\code\\code\\Project_entry\\dataread.txt")
#define ADRESS2 ("F:\\code\\code\\Project_entry\\datasave.txt")
using namespace std;

CInformation::CInformation(){ }
//CInformation::~CInformation(){ }
student *CInformation::creat() {
	char ch[MAX_NUM]; n = 0;
	p1 = p2 = (student*)malloc(LEN);
	cout << "--------<<请建立学生考试信息表，在姓名处键入 stop 结束输入。>>---------" << endl;
	cout << "姓名：";
	cin >> ch;
	head = NULL;
	while (strcmp(ch,"stop") != 0) {
		p1 = (student*)malloc(LEN);
		strcpy_s(p1->name, ch);
		cout << "性别：";
		cin >> p1->sex;
		cout << "准考证号（8位）：";
		cin >> p1->id;
		cout << "数学成绩：";
		cin >> p1->score[0];
		cout << "物理成绩：";
		cin >> p1->score[1];
		cout << "英语成绩：";
		cin >> p1->score[2];
		cout << "C++成绩：";
		cin >> p1->score[3];
		p1->total = p1->score[0] + p1->score[1] + p1->score[2] + p1->score[3];
		if (n == 0) head = p1;
		else p2->next = p1;
		p2 = p1;
		n++;
		cout << "姓名：";
		cin >> ch;
	}
	p2->next = NULL;
	return (head);
}
void CInformation::output(student *head) {
	if (head == NULL) cout << "这是一个空表，请先输入考生成绩.\n";
	else {
		cout << "----------------------------------------------------------------\n";
		cout << "                   *学生成绩信息表*\n";
		cout << "----------------------------------------------------------------\n";
		cout << "准考证号    姓名  性别  数学  物理  英语   C++  平均分  总分\n";
		cout << "----------------------------------------------------------------\n";
		p1 = head;
		do {
			cout << setw(8) << p1->id
			 << setw(8) << p1->name
			 << setw(6) << p1->sex
			 << setw(6) << p1->score[0]
			 << setw(6) << p1->score[1]
			 << setw(6) << p1->score[2]
			 << setw(6) << p1->score[3]
			 << setw(8) << p1->total / 4.0
			 << setw(6) << p1->total << endl;
			cout << "----------------------------------------------------------------\n";
			p1 = p1->next;
		} while (p1 != NULL);
	}
}

int CInformation::count(struct student *head) {
	if (head == NULL) return(0);
	else return(1 + count(head->next));
}

student *CInformation::insert(student *head) {
	cout << "\t-----------<<请输入新增学生成绩信息>>-----------\n" << endl;
	p1 = (student*)malloc(LEN);
	cout << "准考证号（8位）：";
	cin >> p1->id;
	cout << "姓名：";
	cin>>p1->name;
	cout << "性别：";
	cin >> p1->sex;
	cout << "数学成绩：";
	cin >> p1->score[0];
	cout << "物理成绩：";
	cin >> p1->score[1];
	cout << "英语成绩：";
	cin >> p1->score[2];
	cout << "C++成绩：";
	cin >> p1->score[3];
	p1->total = p1->score[0] + p1->score[1] + p1->score[2] + p1->score[3];
	p2 = head;
	if (head == NULL) {
		head = p1; p1->next = NULL;
	}
	else {
		while ((p1->id > p2->id) && (p2->next != NULL)) {
			p3 = p2;
			p2 = p2->next;
		}
		if (p1->id <= p2->id) {
			if (head == p2) {
				p1->next = head;
				head = p1;
			}
			else {
				p3->next = p1;
				p1->next = p2;
			}
		}
		else {
			p2->next = p1;
			p1->next = NULL;
		}
	}
	n++;
	cout << "----------<<你输入的学生信息已经成功插入>>---------" << endl;
	return (head);
}

student *CInformation::cancel(student *head, long int num) {
	if (head == NULL) return(head);
	else {
		p1 = head;
		while (num != p1->id&&p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		if (num == p1->id) {
			if (p1 == head) head = p1->next;
			else p2->next = p1->next;
			cout << "删除准考证号为" << num << "的学生" << endl;
			n--;
		}
		return(head);
	}
}

student *CInformation::find(student *head, long int num) {
	if (head == NULL) {
		cout << "这是一个空表，请先输入考生成绩：" << endl;
		return(head);
	}
	else {
		p1 = head;
		while (num != p1->id&&p1->next != NULL) {
			p1 = p1->next;
		}
		if (num == p1->id) {
			cout << "----------------------------------------------------------------\n";
			cout << "准考证号    姓名  性别  数学  物理  英语   C++  平均分  总分\n";
			cout << "----------------------------------------------------------------\n";
			cout << setw(8) << p1->id
			 << setw(8) << p1->name
			 << setw(6) << p1->sex
			 << setw(6) << p1->score[0]
			 << setw(6) << p1->score[1]
			 << setw(6) << p1->score[2]
			 << setw(6) << p1->score[3]
			 << setw(8) << p1->total / 4.0
			 << setw(6) << p1->total << endl;
			cout << "----------------------------------------------------------------\n";
		}
		else cout << "未找到准考证号为" << num << "的学生.\n";
		return(head);
	}
}

void CInformation::sort(student *head) {
	int i, k, m = 0, j;
	student *p[MAX_NUM];
	if (head != NULL) {
		m = count(head);
		cout << "----------------------------------------------------------------------\n";
		cout << "--------------------------*学生考试成绩统计表*------------------------" << endl;
		cout << "----------------------------------------------------------------------\n";
		cout << "准考证号    姓名  性别  数学  物理  英语   C++  平均分  总分  名次\n";
		cout << "----------------------------------------------------------------------\n";
		p1 = head;
		for (k = 0; k < m; k++) {
			p[k] = p1;
			p1 = p1->next;
		}
		for(k=0;k<m-1;k++)
			for(j=k+1;j<m;j++)
				if (p[k]->total < p[j]->total) {
					p2 = p[k];
					p[k] = p[j];
					p[j] = p[2];
				}
		for (i = 0; i < m; i++) {
			cout << setw(8) << p[i]->id
				<< setw(8) << p[i]->name
				<< setw(6) << p[i]->sex
				<< setw(6) << p[i]->score[0]
				<< setw(6) << p[i]->score[1]
				<< setw(6) << p[i]->score[2]
				<< setw(6) << p[i]->score[3]
				<< setw(8) << p[i]->total / 4.0
				<< setw(6) << p[i]->total
				<< setw(6) << i + 1 << endl;
			cout << "----------------------------------------------------------------------\n";
		}
	}
}

void CInformation::average(student *head) {
	int k, m;
	float arg1 = 0, arg2 = 0, arg3 = 0, arg4 = 0;
	if (head == NULL) {
		cout << "这是一个空表，请先输入考生成绩：" << endl;
	}
	else {
		m = count(head);
		p1 = head;
		for (k = 0; k < m; k++) {
			arg1 += p1->score[0];
			arg2 += p1->score[1];
			arg3 += p1->score[2];
			arg4 += p1->score[3];
			p1 = p1->next;
		}
		arg1 /= m; arg2 /= m; arg3 /= m; arg4 /= m;
		cout << "------------------------*全班单科成绩平均分*--------------------------\n";
		cout << "----------------------------------------------------------------------\n";
		cout << "数学平均分：" << setw(3)<< arg1<<"  "
			<< "物理平均分：" << setw(3) << arg2<<"  "
			<< "英语平均分：" << setw(3) << arg3<<"  "
			<< "C++平均分：" << setw(3) << arg4 << endl;
		cout << "----------------------------------------------------------------------\n";
	}
}

void CInformation::save(student *head) {
	ofstream file_out;
	file_out.open(ADRESS2, ios::out);
	file_out << count(head) << endl;
	while (head != NULL) {
		file_out << head->name << "\t"
			<< head->id << "\t" << "\t"
			<< head->sex << "\t"
			<< head->score[0] << "\t"
			<< head->score[1] << "\t"
			<< head->score[2] << "\t"
			<< head->score[3] << "\t"
			<< head->total << endl;
		head = head->next;
	}
	file_out.close();
}

student *CInformation::Read() {
	int i = 0;
	p1 = p2 = (student*)malloc(LEN);
	head = NULL;
	ifstream in(ADRESS1, ios::in);        //输入输出体系简便写法
	in >> i;
	if (i == 0) {
		cout << "data.txt文件中数据为空，请先输入数据。" << endl;
		return 0;
	}
	else {
		cout << "----------------------------------------------------------------\n";
		for (; i > 0; i--) {
			p1 = (student*)malloc(LEN);
			in >> st.name >> st.id >> st.sex
				>> st.score[0] >> st.score[1] >> st.score[2] >> st.score[3]
				>> st.total;
			strcpy_s(p1->name, st.name);
			p1->id = st.id;
			strcpy_s(p1->sex, st.sex);
			p1->score[0] = st.score[0];
			p1->score[1] = st.score[1];
			p1->score[2] = st.score[2];
			p1->score[3] = st.score[3];
			p1->total = st.total;
			if (n == 0) head = p1;
			else p2->next = p1;
			p2 = p1;
			n++;
			cout << " " << p1->name << "\t"
				<< p1->id << "\t" << "\t"
				<< p1->sex << "\t"
				<< p1->score[0] << "\t"
				<< p1->score[1] << "\t"
				<< p1->score[2] << "\t"
				<< p1->score[3] << "\t";
			cout << "----------------------------------------------------------------\n";
		}
		cout << "数据已经成功读取完毕" << endl;
		p2->next = NULL;
		return(head);
	}
}