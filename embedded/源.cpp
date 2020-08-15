#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//int main() {   //嵌入式常用分离高低位方法：位运算
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


//int main() {   //高低位互换
//	unsigned char v = 0x12;
//	//unsigned char b = ((v & 0xff) << 4) | (v >> 4);   // v & 0xff  好像没有什么意义
//	unsigned char b = (v << 4) | (v >> 4);   
//	cout << hex << int(b) << endl;
//}


//int bit0or1(int it, int position) { //判断某一位是否为1
//	int oc = 1;
//	oc <<= (position - 1);
//	return (oc&it) != 0 ? 1 : 0;
//}


class Stu_Info_Mange   //this指针举例
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
	void Setsname(int sn)   //使用this指针进行赋值  
	{
		this->sname = sn;
	}
	int  Setage(int a)
	{
		this->age = a;
		return (*this).age; //使用this指针返回该对象的年龄  
	}
	void print()
	{
		cout << "the sname is " << this->sname << endl;  //显式this指针通过箭头操作符访问  
		cout << "the sno   is " << sno << endl;//隐式使用this指针打印  
		cout << "the age   is " << (*this).age << endl;//显式使用this指针通过远点操作符  
		cout << "the grade is " << this->grade << endl << endl;
	}

};
//int main()
//{
//	Stu_Info_Mange sim1(761, "张三", 19, 3);
//
//	sim1.print();      //输出信息  
//
//	sim1.Setage(12);  //使用this指针修改年龄  
//
//
//	sim1.print();     //再次输出  
//	return 0;
//}


//int main() {   //linux进程
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