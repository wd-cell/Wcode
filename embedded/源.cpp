#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//int main() {   //Ƕ��ʽ���÷���ߵ�λ������λ����
//	unsigned int offset = 0x1234;
//	unsigned int high = 0;
//	unsigned int low = 0;
//	high = ((offset >> 8) & 0xff);
//	low = (offset & 0xff);
//	cout << high << endl;
//	cout << low << endl;
//	cout << hex << offset << endl;
//	cout << hex << (offset >> 8) << endl;
//}


//int main() {   //�ߵ�λ����
//	unsigned char v = 0x12;
//	//unsigned char b = ((v & 0xff) << 4) | (v >> 4);   // v & 0xff  ����û��ʲô����
//	unsigned char b = (v << 4) | (v >> 4);   
//	cout << hex << int(b) << endl;
//}


//int bit0or1(int it, int position) { //�ж�ĳһλ�Ƿ�Ϊ1
//	int oc = 1;
//	oc <<= (position - 1);
//	return (oc&it) != 0 ? 1 : 0;
//}


class Stu_Info_Mange   //thisָ�����
{
	int sno;
	string sname;
	int age;
	int grade;
public:
	Stu_Info_Mange(int s = 0, string n = "", int a = 0, int g = 0)
	{
		sno = s;
		sname = n;
		age = a;
		grade = g;
	}
	void Setsname(int sn)   //ʹ��thisָ����и�ֵ  
	{
		this->sname = sn;
	}
	int  Setage(int a)
	{
		this->age = a;
		return (*this).age; //ʹ��thisָ�뷵�ظö��������  
	}
	void print()
	{
		cout << "the sname is " << this->sname << endl;  //��ʽthisָ��ͨ����ͷ����������  
		cout << "the sno   is " << sno << endl;//��ʽʹ��thisָ���ӡ  
		cout << "the age   is " << (*this).age << endl;//��ʽʹ��thisָ��ͨ��Զ�������  
		cout << "the grade is " << this->grade << endl << endl;
	}

};
//int main()
//{
//	Stu_Info_Mange sim1(761, "����", 19, 3);
//
//	sim1.print();      //�����Ϣ  
//
//	sim1.Setage(12);  //ʹ��thisָ���޸�����  
//
//
//	sim1.print();     //�ٴ����  
//	return 0;
//}


//int main() {   //linux����
//	pid_t pid;
//	pid = fork();
//	if(pid==0){...}
//	if(pid==1){...}
//}


//int main() {   //NULL==NULL?
//	if (NULL == NULL)
//		cout << 1 << endl;
//	else
//		cout << 2 << endl;
//}