#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>
#include<string>
#include<ctime>
#include<vector>
#include"SORT.h"
using namespace std;



//double power(double x, int n);//����x��n�η�            //������ʮ����ת��
//int main() {
//	int value = 0;
//	cout << "Enter an 8 bit binary number ";
//	for (int i = 7; i >= 0; i--) {
//		char ch;
//		cin >> ch;
//		if (ch == '1')
//			value += static_cast<int>(power(2, i));
//	}
//	cout << "Decimal value is " << value << endl;
//	return 0;
//}
//double power(double x, int n) {
//	double val = 1.0;
//	while (n--)
//		val *= x;
//	return val;
//}



//double arctan(double x) {                        //PI
//	double sqr = x * x;
//	double e = x;
//	double r = 0;
//	int i = 1;
//	while (e / i > 1e-15) {
//		double f = e / i;
//		r = (i % 4 == 1) ? r + f : r - f;
//		e = e * sqr;
//		i += 2;
//	}
//	return r;
//}
//int main() {
//	double a = 16.0 * arctan(1 / 5.0);
//	double b = 4.0 * arctan(1 / 239.0);
//	/* ע�⣺��Ϊ����������ȡ�����������д1/5��1/239������Ͷ���0 */
//	cout << "PI = " << a - b << endl;
//	return 0;
//}



//int main() {      //������Ŀ
//	char s[] = "abccda";
//	char c;
//	for (int i = 1; (c = s[i]) != '\0'; i++) {
//		switch (c) {
//		case 'a':cout << "%";
//			continue;
//		case 'b':cout << "$";
//		case 'c':cout << "*";
//			break;
//		case 'd':continue;
//		}
//		cout << "#" << endl;
//	}
//}



//int main() {   //KMP�㷨
//	string s1;
//	while (cin >> s1) {
//		string s2;
//		cin >> s2;
//		cout << KMP(s1, s2) << endl;
//	}
//}



//int main() {   //size,sizeof,length,strlen����
//	string a = "abcde";
//	cout << size(a) << endl << sizeof(a) << endl << a.length() << endl;
//	char b[] = "abcde";
//	cout << sizeof(b) << endl << strlen(b) << endl;
//	system("pause");
//}



//#include<cstdio>   //�����������ǰ�к�ͬ�����ǵݹ飬����ѭ��
//#include<queue>
//using namespace std;
///*�������ṹ�壬���ҹ������вι��캯��*/
//struct BinaryTree {
//	int vec;
//	BinaryTree* left;
//	BinaryTree* right;
//	BinaryTree(int data)
//		:vec(data), left(nullptr), right(nullptr) {
//	}
//};
///*����ʵ�ֲ������*/
//void printTree(BinaryTree* arr[])
//{
//	queue<BinaryTree*> rel; //����һ�����У����������Ƕ�����ָ�룬��Ҫ����int������Ȼ�޷�����
//	rel.push(arr[0]);
//	while (!rel.empty())
//	{
//		BinaryTree* front = rel.front();
//		printf("%d\n", front->vec); //�������
//		rel.pop();                  //ɾ����ǰ��Ľڵ�
//		if (front->left != nullptr) //�ж���ǰ�����ڵ��Ƿ�Ϊ�գ�������������
//			rel.push(front->left);
//		if (front->right != nullptr)//�ж���ǰ����ҽڵ��Ƿ�Ϊ�գ�������������
//			rel.push(front->right);
//	}
//}
//int main() {
//	/*����������*/
//	BinaryTree* s_arr[6];
//	s_arr[0] = new BinaryTree(0);
//	s_arr[1] = new BinaryTree(1);
//	s_arr[2] = new BinaryTree(2);
//	s_arr[3] = new BinaryTree(3);
//	s_arr[4] = new BinaryTree(4);
//	s_arr[5] = new BinaryTree(5);
//	s_arr[0]->left = s_arr[1];  //   0
//	s_arr[0]->right = s_arr[2]; //  1  2
//	s_arr[1]->left = s_arr[3];  // 3     5
//	s_arr[3]->left = s_arr[4];  //4
//	s_arr[2]->right = s_arr[5]; //���Բ�������Ľ��Ϊ��0 1 2 3 5 4
//	/*��α�����ӡ���нڵ�*/
//	printTree(s_arr);
//	/*�ͷ����пռ�*/
//	for (int i = 0; i < 6; i++)
//		delete s_arr[i];
//	system("pause");
//	return 0;
//}



//int main() {   //��̬�ڴ�����ᱻ�ڲ㸲�ǣ���Ҫ������ָ��̬�ڴ��ָ����ָ��𴦡�
//	int *a = new int(0);
//	int b = 10,c=2;
//	//int *a=&b;
//	//a = &b;   //�˴������*aָ��b��û��ָ��ָ��̬�ڴ���
//	*a = 10;
//	cout << *a << endl;
//	while (1) {
//		int *a=&c;
//		*a = 2;
//		cout << *a << endl;
//		break;
//		//delete a;
//	}
//	cout << *a << endl;
//	delete a;
//	system("pause");
//}



//#include<deque>   //˫���б��б�
//#include<queue>
//int main() {
//	queue<int> a;
//	deque<char> b;
//}



//#include"Point.h"   //new��malloc
//int main() {
//	Point a;
//	Point *b = &a;
//	int *c = (int*) malloc(sizeof(int));
//	int *d = new(int);
//}



//#include"LinkList.h"   //linklist��ʵ��
//#include<Windows.h>
//int main()
//{
//	LinkList A;
//	A.Creat();
//	LinkList* B = new(LinkList);
//	LinkList *C = new LinkList;
//	LinkList *D = new LinkList();
//	int *a = new int(2);
//	int *b = new(int);
//
//	Sleep(6000);   //��ʱ6��
//	A.Display();
//	A.HeadInsertNode(99);
//	A.Display();
//	A.EndInsertNode(88);
//	A.Display();
//	A.Reverse();
//	A.Display();
//	A.IndexInsertNode(3, 888);
//	A.Display();
//	A.DeleteIndexNode(2);
//	A.Display();
//	system("pause");
//
//	return 0;
//}



//int main() {   //n&(n-1)
//		int n, count = 0;
//		cin >> n;
//		while (n > 0)
//		{
//			count++;
//			n &= (n - 1);
//		}
//		cout << count << endl;
//		system("pause");
//}



//#include<iostream>   //��С�������㷨
//#include "Graph.h"
//using namespace std;
//
//int main()
//{
//	Graph G;
//	G.CreateGraph();
//	cout << "��С��������" << endl;
//	G.MiniSpanTree_Prim();
//	system("pause");
//	return 0;
//}



//class A {
//public:
//	void fun(int a) {
//		cout << "fun a" << endl;
//	}
//};
//class B :public A {
//public:
//	void fun(string a) {
//		cout << "fun b" << endl;
//	}
//};
//int main() {
//	B b;
//	b.fun("a");
//	//b.fun(1);
//}



#include<unordered_map>   //unordered_map�����򲢲��ǲ���˳����Ǳ���˳�򣬶��ǹ�ϣ��û���������
void unordered_map_test() {
	unordered_map<char, int> m;
	m['A'] = 10;
	m['a'] = 1;
	m['c'] = 3;
	m['b'] = 2;
	m['C'] = 11;
	for (auto i : m)
		cout << i.first << ": " << i.second << endl;
}



//#include"��ϰ.h"   //���캯�������麯��
//int main() {
//	A a;
//	a.Function();
//	Base* b = dynamic_cast<Base*>(&a);
//	b->Function();
//
//	//a.a = new Base;
//	//a.~Base();
//}



//int main() {   //�����
//	srand((int)time(0));
//	for (int i = 0; i < 10; ++i)
//		cout << rand() % 10 << " ";
//}



//int main() {
//	//int a, b, c;
//	//c = 2;
//	//a = b = c + 1;
//	//cout << a << b << c;
//
//	//char* s;
//	//scanf_s("%s", s);   //s��Ұָ�룬�޷���ֵ
//
//	int i = 0;
//	if (i++ == 0)
//		cout << i << endl;
//	else
//		return i + 10;
//}



//int main() {
//	vector<int> v = { 1,2,3,4,5,6 };
//	auto it = v.begin() + 2;
//	cout << *it << endl;
//	it = v.erase(it);   //������ʧЧ
//	cout << *it << endl;
//}



//int main() {   //size,capacity,resize,reserveʹ��
//	vector<int> v = { 1,2,3 };
//	cout << v.capacity() << endl;
//	v.resize(6);
//	cout << v.size() << v[0]<<endl;
//	for (int i : v)
//		cout << i << ' ';
//	cout << endl;
//
//	//v.reserve(0);   
//	cout << v.capacity() << endl;
//}



class Window_mgr
{
public:
	void clear();
};

class Screen
{
	friend void Window_mgr::clear();
private:
	unsigned cursor = 0;
	unsigned height = 0, width = 0;
	std::string contents;
public:

	Screen() = default;//��ΪScreen����һ�����캯�������Ա������Ǳ����
	//cuesor�������ڳ�ʼ��Ϊ0
	Screen(unsigned ht, unsigned wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
	Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
	Screen move(unsigned r, unsigned c)
	{
		cursor = r * width + c;
		return *this;
	}
	Screen set(char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen set(unsigned r, unsigned c, char ch)
	{
		contents[r * width + c] = ch;
		return *this;
	}
	Screen& display()
	{
		std::cout << contents;
		return *this;
	}
};
void testScreen()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0);
	myScreen.set('#').display();
	cout << endl;
	myScreen.display();
	cout << "\n";
	myScreen.set(4, 0, 'A');
	myScreen.display();
	cout << "\n";
	//return 0;

	Screen myScreen1(5, 5, 'X');
	myScreen1.move(4, 0).set('#').display();
	cout << "\n";
	myScreen1.display();
	cout << "\n";

	////7.32
	//Window_mgr w;
	//w.clear();
	//return 0;
}



#include"testMysql.h"

#include"ThreadPool.h"







//int main() {
//	testThread();
//}