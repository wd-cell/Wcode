#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>
#include<string.h>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cctype>
#include<list>
#include<fstream>
using namespace std;


//int main()                                      //prime number
//{
//	int nStart = 0, nEnd = 0;
//	int nCnt1 = 0, nCnt2 = 0;
//	int nSqrt;
//	int nNum = 0;
//	cout << "��������������Сֵ��";
//	cin >> nStart;
//	cout << "���������������ֵ��";
//	cin >> nEnd;
//	for (nCnt1 = nStart; nCnt1 <= nEnd; nCnt1 += 2) {
//		nSqrt = sqrt(nCnt1);
//		for (nCnt2 = 2; nCnt2 <= nSqrt; nCnt2++)
//			if (nCnt1%nCnt2 == 0) break;
//		if (nCnt2 >= nSqrt + 1) {
//			cout << nCnt1 << " ";
//			nNum++;
//			if (nNum % 10 == 0) cout << endl;
//		};
//	};
//	cout << endl;
//	return 0;
//}



//int main(int argc, char*argv[])                          //matrix product
//{
//	int m[3][4] = { {1,2,3,4},{2,2,3,1},{5,4,2,3} };
//	int n[4][3] = { {6,3,2},{2,8,1},{6,9,5},{2,4,6} };
//	int i, j, k;
//	int q[3][3];
//	memset(q, 0, sizeof(q));
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//			for (k = 0; k < 4; k++)
//				q[i][j] = q[i][j] + m[i][k] * n[k][j];
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//			cout << q[i][j] << "  ";
//		cout << endl;
//	}
//	return 0;
//}



//void Swap(int, int);                              //ʵ���β�
//int main(int argc, char*argv[]) {
//	int m = 11, n = 22;
//	cout << "m=" << m << ",n=" << n << endl;
//	Swap(m, n);
//	cout << "m=" << m << ",n=" << n << endl;
//	return 0;
//}
//void Swap(int a, int b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}



//int lcm(int, int);                               //greatest common divisor and least common multiple
//int gcd(int, int);
//int main(int argc, char*argv[])
//{
//	int m, n;
//	cout << "�����������Ǹ�����";
//	cin >> m >> n;
//	cout << "gcd(" << m << "," << n << ")=" << gcd(m, n) << endl;
//	cout << "lcm(" << m << "," << n << ")=" << lcm(m, n) << endl;
//	return 0;
//}
//int gcd(int m, int n)
//{
//	while (n > 0) {
//		int r = m % n;
//		m = n;
//		n = r;
//	}
//	return m;
//}
//int lcm(int m, int n)
//{
//	return (m*n / gcd(m, n));
//}



//const int Len = 66;                                  //111ͼ�����
//const int Divs = 6;
//void subdivide(char ar[], int low, int high, int level);
//using namespace std;
//int main() {
//	char ruler[Len];
//	int i;
//	for (i = 1; i < Len - 2; i++)
//		ruler[i] = ' ';
//	ruler[Len - 1] = '\0';
//	int max = Len - 2;
//	int min = 0;
//	ruler[min] = ruler[max] = 'l';
//	cout << ruler << endl;
//	int j;
//	for (i = 1; i <= Divs; i++)
//	{
//		subdivide(ruler, min, max, i);
//		cout << ruler << endl;
//		for (j=1;j < Len - 2; j++)
//		ruler[j] = ' ';
//	}
//	return 0;
//}
//void subdivide(char ar[], int low, int high, int level)
//{
//	if (level == 0)
//		return;
//	int mid = (high + low) / 2;
//	ar[mid] = '1';
//	subdivide(ar, low, mid, level - 1);
//	subdivide(ar, mid, high, level - 1);
//}



//void print_teacher();                                //ָ������ָ��
//void print_student();
//void print_body(void(*pFuc)());
//int main() {
//	void(*print_message)();
//	int nChoose = 0;
//	cout << "ѡ�� 1����ʦ  2��ѧ��." << endl;
//	cin >> nChoose;
//	if (nChoose == 1) print_message = print_teacher;
//	else if (nChoose == 2) print_message = print_student;
//	else { cout << "ѡ�����." << endl; exit(1); };
//	print_body(print_message);
//	return 0;
//};
//void print_teacher() {
//	cout << "��ʦ���������" << endl;
//	cout << "���̿γ̣�C++" << endl;
//};
//void print_student() {
//	cout << "ѧ�����������" << endl;
//	cout << "��ѧ�γ̣�C++" << endl;
//};
//void print_body(void(*pFuc)()) {
//	pFuc();
//}



//#define random(a,b) (rand()%(b-a))                     //���ɶ�̬�������
//using namespace std;
//int main(int agrc, char*agrv[]) {
//	long nCnt = 0;
//	cout << "��������Ԫ�ظ�����";
//	cin >> nCnt;
//	srand(time(NULL));
//	int *pnArray = new int[nCnt];
//	if (pnArray == NULL) exit(1);
//	memset((void*)pnArray, 0x00, sizeof(int)*nCnt);
//	for (long Loop = 0; Loop < nCnt; Loop++) {
//		pnArray[Loop] = random(0, 100);
//		cout << pnArray[Loop] << endl;
//	};
//	delete[] pnArray;
//	pnArray = NULL;
//	return 0;
//}



//#define random(a,b) (rand()%(b-a))                      //��ά��̬����Ĵ������ͷ�
//using namespace std;
//int main() {
//	long **ppArray = new long*[5];
//	srand(time(NULL));
//	for (int nLoop1 = 0; nLoop1 < 5; nLoop1++) {
//		ppArray[nLoop1] = new long[5];
//		memset(ppArray[nLoop1], 0x00, sizeof(long) * 5);
//	};
//	for (int nLoop1 = 0; nLoop1 < 5; nLoop1++) {
//		int nNum = 0;
//		for (int nLoop2 = 0; nLoop2 < 5; nLoop2++) {
//			ppArray[nLoop1][nLoop2] = random(0, 100);
//			cout << setw(6) << ppArray[nLoop1][nLoop2] << " ";
//			nNum++;
//			if (nNum % 5 == 0) cout << endl;
//		};
//	};
//	for (int nLoop2 = 0; nLoop2 < 5; nLoop2++) {
//		delete[] ppArray[nLoop2];
//		ppArray[nLoop2] = NULL;
//	};
//	delete[] ppArray;
//	ppArray = NULL;
//	return 0;
//}



//int main() {                                 //switch
//	int day;
//	cout << "�����ܼ���";
//	cin >> day;
//	switch (day) {
//	case 0:cout << "Sunday" << endl; break;
//	case 1:cout << "Monday" << endl; break;
//	case 2:cout << "Tuesday" << endl; break;
//	case 3: cout << "Wednesday" << endl; break;
//	case 4:cout << "Thursday" << endl; break;
//	case 5:cout << "Friday" << endl; break;
//	case 6:cout << "Saturday" << endl; break;
//	default:
//		cout << "Day out of range Sunday .. Saturday"
//			<< endl;
//		break;
//	}
//	return 0;
//}



//enum GameResult { WIN, LOSE, TIE, CANCEL };              //enum
//int main() {
//	GameResult result;
//	GameResult omit = CANCEL;
//	for (int count = WIN; count <= CANCEL; count++) {
//		result = GameResult(count);
//		if (result == omit)
//			cout << "The game was cancelled" << endl;
//		else {
//			cout << "The game was played ";
//			if (result == WIN)
//				cout << "and we won!";
//			if (result == LOSE)
//				cout << "and we lost.";
//			cout << endl;
//		}
//	}
//	return 0;
//}



//int& GetMaxForArray(int arr[], int nSize);                //������Ϊ��������ֵ��ȡ�������ֵ��
//int main() {
//	int nArray[10] = { 2,3,4,1,5,34,43,31,90,85 };
//	int max = GetMaxForArray(nArray, 10);
//	cout << max << endl;
//	return 0;
//}
//int& GetMaxForArray(int arr[], int nSize) {
//	int nMax(arr[0]), index(0);  //�൱��  int nMax=arr[0], index=0;   
//	for (int nCnt = 1; nCnt < nSize; nCnt++) {
//		if (arr[nCnt] > nMax) {
//			nMax = arr[nCnt];
//			index = nCnt;
//		};
//	}
//	return arr[index];
//}



//struct birthday {                         //�ṹ������Ӧ��
//	short year;
//	short month;
//	short day;
//};
//struct employee {
//	int no;
//	char name[20];
//	short sex;
//	int age;
//	struct birthday birth;
//	float salary;
//};
//int main() {
//	employee emp[5] = {
//		{9901,"zhangsan",0,27,{1981,11,7},8600},
//	{9902,"wangjuan",1,21,{1987,1,12},3200},
//	{9903,"wangwu",0,20,{1988,2,5},2500},
//	{9904,"tanli",0,26,{1982,8,25},6800},
//	{9905,"linli",0,23,{1985,8,28},2900}
//	};
//	cout << "People who earn more than 5000 is:" << endl;
//	cout << setw(5) << "Number" << setw(15) << "Name" << endl;
//	for (int nCnt = 0; nCnt < 5; nCnt++) {
//		if (emp[nCnt].salary > 5000)
//			cout << setw(5) << emp[nCnt].no << setw(15) << emp[nCnt].name << endl;
//	}
//	return 0;
//}



//int main() {                                      //�ַ�������
//	int len;
//	cout << "�����ַ�������󳤶�:";
//	cin >> len;
//	char *p = new char[len];
//	memset(p, 0x00, sizeof(char)*len);
//	cout << "������ַ��������ǣ�";
//	cin >> p;
//	cout << "������ַ����ǣ�" << p << endl;
//	cout << "���д�д��ĸ�У�";
//	char *pTemp = p;
//	while (*pTemp != '\0') {
//		if (isupper(*pTemp)) cout << *pTemp;
//		pTemp++;
//	};
//	delete p;
//	return 0;
//}



//#include"Phone.h"                                     //��
//int main(int argc, char*argv[]) {
//	CMobiePhone CMP_A1200;
//	CMP_A1200.SetPhoneName();
//	CMP_A1200.SetPhoneType();
//	CMP_A1200.SetPhoneSize();
//	CMP_A1200.ShowPhoneName();
//	CMP_A1200.ShowPhoneType();
//	CMP_A1200.ShowPhoneSize();
//	return 0;
//};



//#include"Ccomplex.h"                         //������������
//int main() {
//	Ccomplex a(1, 2), b(3, 4);
//	Ccomplex::ShowComplex(a++);
//	Ccomplex::ShowComplex(a);
//	Ccomplex::ShowComplex(b++);
//	return 0;
//}



//enum Tsex{mid,man,woman};                     //�̳��������ۺ�ʵ��
//class Person {
//	string IDPerson;
//	string Name;
//	Tsex Sex;
//	int Birthday;
//	string Homeadress;
//public:
//	Person(string, string, Tsex, int, string);       //���ι��캯��������ֻ����������ͣ�
//	//Person();                                        //�ղι��캯������
//	~Person();
//	void PrintPersonInfo();
//};
//Person::Person(string id, string name, Tsex sex, int birthday, string homeadd) {
//	cout << "����Person" << endl;
//	IDPerson = id;
//	Name = name;
//	Sex = sex;
//	Birthday = birthday;
//	Homeadress = homeadd;
//}
////Person::Person() {
////	cout << "����Person" << endl;
////	Sex = mid;
////	Birthday = 0;
////}
//Person::~Person() {
//	cout << "����Person" << endl;
//}
//void Person::PrintPersonInfo() {
//	int i;
//	cout << "���֤�ţ�" << IDPerson << '\n' << "����:" << Name << '\n' << "�Ա�";
//	if (Sex == man)cout << "��" << endl;
//	else if (Sex == woman)cout << "Ů" << endl;
//	else cout << " " << endl;
//	cout << "���������գ�";
//	i = Birthday;
//	cout << i / 10000 << "��";
//	i = i % 10000;
//	cout << i / 100 << "��" << i % 100 << "��" << '\n' << "��ͥסַ��" << Homeadress << '\n';
//}
//
//class Student :public virtual Person {                     //������ඨ�幫��������ѧ����
//	string NoStudent;
//public:
//	Student(string id, string name, Tsex sex, int birthday, string homeadd, string nostud);//ע�������๹�캯��������ʽ
//	//Student();
//	~Student() { cout << "����Student" << endl; };
//	void PrintStudentInfo();
//};
//Student::Student(string id, string name, Tsex sex, int birthday, string homeadd, string nostud)
//	:Person(id, name, sex, birthday, homeadd) {     //ע��Person������������
//	cout << "����Student" << endl;
//	NoStudent = nostud;
//}
////Student::Student() {                                //����ȱʡ���޲ι��캯��������ʽ����
////	cout << "����Student" << endl;
////}
//void Student::PrintStudentInfo() {
//	cout << "ѧ�ţ�" << NoStudent << endl;
//	PrintPersonInfo();                              //���û���PrintPersonInfo����
//}
//
//class GStudent :public Student {
//	string NoGStudent;
//public:
//	GStudent(string id, string name, Tsex sex, int birthday, string homeadd, string nostud,
//		string nogstudent);                         //ע�������๹�캯��������ʽ
//	//GStudent();
//	~GStudent() { cout << "����GStudent" << endl; }
//	void PrintGStudentInfo();
//};
//GStudent::GStudent(string id, string name, Tsex sex, int birthday, string homeadd, string nostud,
//	string nogstudent) :Student(id, name, sex, birthday, homeadd, nostud), Person(id, name, sex,
//		birthday, homeadd) {
//	//��Person������࣬���ܲ���ֱ�ӻ��࣬�綨��GStudent����Person�������
//	//���������ɲ����֣�Ϊͨ��Ӧ���֣��粻������࣬�����Ǵ����
//	cout << "����GStudent" << endl;
//	NoGStudent = nogstudent;
//}
////GStudent::GStudent() {                               //����ȱʡ���޲ι��캯��������ʽ����
////	cout << "����GStudent" << endl;
////}
//void GStudent::PrintGStudentInfo() {
//	cout << "�о����ţ�" << NoGStudent << '\n';
//	PrintStudentInfo();
//}
//
//class Employee :public virtual Person {
//	string NoEmployee;
//public:
//	Employee(string id, string name, Tsex sex, int birthday, string homeadd, string noempl);
//	//ע�������๹�캯��������ʽ
//	//Employee();
//	~Employee() { cout << "����Employee" << endl; }
//	void PrintEmployeeInfo();
//	void PrintEmployeeInfo1();                     //���ؼ̳�ʱ�����ظ���ӡ�����Person����Ϣ
//};
//Employee::Employee(string id, string name, Tsex sex, int birthday, string homeadd, string noempl)
//	:Person(id, name, sex, birthday, homeadd) {    //ע��Person�����ɲ�������
//	cout << "����Employee" << endl;
//	NoEmployee = noempl;
//}
////Employee::Employee() { cout << "����Employee" << endl; }   //����ȱʡ���޲ι��캯��������ʽ����
//void Employee::PrintEmployeeInfo() {
//	cout << "��ְ���ţ�" << NoEmployee << '\n';
//	PrintPersonInfo();
//}
//void Employee::PrintEmployeeInfo1() {
//	cout << "��ְ���ţ�" << NoEmployee << '\n';
//}
//
//class EGStudent :public Employee, public GStudent {
//	string NoEGStudent;
//public:
//	EGStudent(string id, string name, Tsex sex, int birthday, string homeadd, string nostud,
//		string nogstud, string noempl, string noegstud);            //ע�������๹�캯��������ʽ
//	//EGStudent();
//	~EGStudent() { cout << "����EGStudent" << endl; }
//	void PrintEGStudentInfo();
//};
//EGStudent::EGStudent(string id, string name, Tsex sex, int birthday, string homeadd, string nostud,
//	string nogstud, string noempl, string noegstud)
//	:GStudent(id, name, sex, birthday, homeadd, nostud, nogstud),
//	Employee(id, name, sex, birthday, homeadd, noempl),
//	Person(id, name, sex, birthday, homeadd) {               //ע��Ҫ����EGStudent����Person�������
//	cout << "����EGStudent" << endl;
//	NoEGStudent = noegstud;
//}
////EGStudent::EGStudent() { cout << "����EGStudent" << endl; }   //����ȱʡ���޲ι��캯��������ʽ����
//void EGStudent::PrintEGStudentInfo() {
//	cout << "��ְѧϰ�ţ�" << NoEGStudent << '\n';
//	PrintEmployeeInfo1();
//	PrintGStudentInfo();
//}
//int main() {
//	EGStudent egstu1("320102810504161", "����", man, 19810504, "�����г�����1��",
//		"06000123", "034189", "06283", "030217");
//	egstu1.PrintEGStudentInfo();
//	GStudent gstu1("3201028211078161", "����", man, 19821107, "�����г�����2��",
//		"08000312", "058362");
//	gstu1.PrintGStudentInfo();
//	return 0;
//}



//#include"cbase.h"                          //�麯�����̬��
//#include"cbase1.h"
//#include"cinheritcls.h"
//void display(cBase& pbase) {              //�˴�ֻ���û��༴��
//	pbase.display();
//};
//int main() {
//	cBase1 b1;
//	cInheritcls i2;
//	display(b1);
//	display(i2);
//	return 0;
//}



//#include"Util.h"                            //STL�ۺ�ʵ��
//int main() {
//	vector<string> vecWords;
//	cout << "���뵥�ʿ⣨����q!�˳�����" << endl;
//	string sWord;
//	while (cin >> sWord && sWord != "q!" && !Util::isNullString(sWord))
//		vecWords.push_back(sWord);
//	if (vecWords.size() == 0) {
//		cout << "δ������Ч�ĵ���" << endl;
//		exit(1);
//	}
//	
//	cout << "�����������µ��ʣ�\n";
//	for_each(vecWords.begin(), vecWords.end(), Util::display);
//	cout << endl;
//
//	set<string> setWords;
//	transform(vecWords.begin(), vecWords.end(), insert_iterator<set<string> >(setWords, setWords.begin()), Util::Tolower);
//	cout << "���ʰ�����ĸ����ȥ���ظ����ʣ���" << endl;
//	for_each(setWords.begin(), setWords.end(), Util::display);
//	cout << endl;
//
//	map<string, int> mapWords;
//	set<string>::iterator it;
//	for (it = setWords.begin(); it != setWords.end(); it++)
//		mapWords[*it] = count(vecWords.begin(), vecWords.end(), *it);
//	cout<<endl << "���ʳ���Ƶ�ȣ�" << endl;
//	for (it = setWords.begin(); it != setWords.end(); it++)
//		cout << *it << ":" << mapWords[*it] << endl;
//
//	multimap <string, string> mulMapWords;
//	vector<string>::iterator vec_it = vecWords.begin();
//	while (vec_it != vecWords.end()) {
//		string strKey;
//		strKey = Util::getInitial(*vec_it);
//		mulMapWords.insert(make_pair(strKey, (string)*vec_it));
//		vec_it++;
//	};
//
//	string strInitial;
//	typedef multimap <string, string>::const_iterator MULMAP_CIT;
//	pair<MULMAP_CIT, MULMAP_CIT> pairSearched;
//	cout << "����Ҫ�������ʵ�����ĸ������q!�˳�����" << endl;
//	while (cin >> strInitial && strInitial != "q!" && !Util::isNullString(strInitial)) {
//		transform(strInitial.begin(), strInitial.end(), strInitial.begin(), toupper);
//		int nWordBeSearched = mulMapWords.count(strInitial);
//		if (nWordBeSearched == 0) {
//			cout << "δ�ҵ���Ӧ�ĵ���" << endl;
//		}
//		else {
//			cout << "�������ĵ����У�" << endl;
//			pairSearched = mulMapWords.equal_range(strInitial);
//			for (MULMAP_CIT i = pairSearched.first; i != pairSearched.second; ++i)
//				cout << i->second << endl;
//		};
//		cout << "����Ҫ�������ʵ�����ĸ������q!�˳�����" << endl;
//	};
//	return 0;
//



//#define ADRESSS ("F:\\code\\c++\\Project1_primer\\a_out.txt")     //���ı��ļ���������
//int main(int argc,char* argv[]) {
//	ofstream file_out;  //����
//	file_out.open(ADRESSS, ios::out | ios::app);
//	if (file_out.fail()) {
//		cerr << "�ļ���ʧ��" << endl;
//		return 1;
//	}
//
//	//���ò���������������
//	file_out << "A B C D E F G" << endl;
//	file_out << "H I J K L M N" << endl;
//	file_out << "O P Q  R S T" << endl;
//	file_out << "U V W X Y Z" << endl;
//
//	//����put()��Ա���������������
//	for (int i = 65; i <= 90; i++) {
//		file_out.put(i);
//		file_out.put(32);
//		switch (i) {
//		case 71: {file_out.put(10); break; };
//		case 78: {file_out.put(10); break; };
//		case 84: {file_out.put(10); break; };
//		case 90: {file_out.put(10); break; };
//		default:break;
//		}
//	}
//	file_out.close();
//	return 0;
//}



//#define ADRESSS ("F:\\code\\c++\\Project1_primer\\b_in.txt")      //��ȡ�ı��ļ�����
//int main() {
//	ifstream file_in(ADRESSS, ios::in);
//	if (file_in.fail()) {
//		cerr << "�ļ���ʧ��" << endl;
//		return 1;
//	}
//
//	//   //���ö�ȡ��������ȡ�ı�����
//	//char nRead;
//	//while (file_in >> nRead)
//	//	cout << nRead << " ";
//
//	//   //����get()��Ա������ȡ�ı�����
//	//while (!file_in.eof()) {         //eof()���������ж��ļ�ָ���Ƿ�ָ��ĩβ
//	//	char nRead;
//	//	nRead = file_in.get();
//	//	cout << nRead;
//	//}
//
//	//   //����get(char& c)��Ա������ȡ�ı�����
//	//char c;
//	//while (!file_in.eof()) {
//	//	file_in.get(c);
//	//	cout << c;
//	//}
//
//	   //����getline()��Ա������ȡ�ı����ݣ��˷���һ�ο��Զ�ȡһ���ı��飬Ч�����
//	char* buf = new char[128];
//	memset(buf, 0x00, 128);
//	while (!file_in.eof()) {
//		file_in.getline(buf, 128);
//		cout << buf << endl;
//		memset(buf, 0x00, 128);
//	}
//	delete[] buf;
//
//	file_in.close();
//	return 0;
//}



#include"Information.h"                   //���������ϵ�ۺ�ʵ����ѧ������ϵͳ
vector<student> stu;

void testStudentManage() {
	CInformation person;
	student *head = NULL;
	int choice;
	long int i;
	do {
		cout<<endl << "0.�ⲿ��������" << endl;
		cout << "1.����ѧ���ɼ�" << endl;
		cout << "2.��ʾѧ���ɼ�" << endl;
		cout << "3.����ѧ���ɼ�" << endl;
		cout << "4.����ѧ���ɼ�" << endl;
		cout << "5.����ѧ���ɼ�" << endl;
		cout << "6.ɾ��ѧ���ɼ�" << endl;
		cout << "7.��ȫ�˳�ϵͳ" << endl;
		cout << "����������ѡ��0--7����";
		cin >> choice;
		switch (choice) {
		case 0:head = person.Read(); break;
		case 1:head = person.creat(); break;
		case 2:person.output(head); break;
		case 3:person.sort(head);
			person.average(head);
			cout << "�μӿ��Ե�ѧ������Ϊ��" << person.count(head) << "��\n"; break;
		case 4:cout << "������Ҫ���ҵ�׼��֤�ţ�8λ����";
			cin >> i;
			person.find(head, i);
			break;
		case 5:head = person.insert(head);
			person.output(head);
			break;
		case 6:cout << "������Ҫɾ����׼��֤�ţ�8λ����";
			cin >> i;
			head = person.cancel(head, i);
			person.output(head);
			break;
		case 7:person.save(head); break;
		default:cout << "�����������������롣" << endl; break;
		}
	} while (choice != 7);
}


#include"Solution38.h"
int main() {
	Solution38 t;
	string ans = t.countAndSay(6);
	cout << ans << endl;
}



//int main() {
//	testStudentManage();
//}