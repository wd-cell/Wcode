#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

using namespace std;//��ֵ�������ֵĸ���
//int main() {
//	int currval = 0, val ;//�������κκ������ⲿ�ı�������ʼ��Ϊ0,�˴�������ʼ������val��δ�����
//	if (cin >> currval) {
//		int cnt = 1;
//		while (cin >> val) {
//			if (currval == val) {
//				cnt++;
//			}
//			else {
//				cout << currval << " occurs " << cnt << " times" << endl;
//				currval = val;
//				cnt = 1;
//			}
//		}
//		cout << currval << " occurs " << cnt << " times" << "\12" << endl;
//	}
//	return 0;
//}



#include<typeinfo>      //typeid().name�䷵������
//int main() {
//	const int i=42;
//	auto j = i;
//	const auto &k = i;
//	auto *p = &i;
//	const auto j2 = i, &k2 = i;
//	cout << typeid(i).name() << endl;
//	cout << typeid(j).name() << endl;
//	cout << typeid(k).name() << endl;
//	cout << typeid(p).name() << endl;
//	cout << typeid(j2).name() << endl;
//	cout << typeid(k2).name() << endl;
//	return 0;
//}



#include<string>            //getline����ͨcin�Աȣ�ǰ�߱����հ׷��������������ÿ��һ���հ׷����
//int main() {
//	string word;
//	while (cin >> word)
//		cout << word << endl;
//
//	string line;
//	while (getline(cin, line))
//		cout << line << "   " << line.size() << endl;
//	return 0;
//}



#include<string>      //15λ���µ�decתhex
//int main() {
//	const string hexdigits = "0123456789ABCDEF";
//	cout << "Enter a series of numbers betweem 0 and 15"
//		<< "separated by spaces. Hit ENTER when finished:"
//		<< endl;
//	string result;
//	string::size_type n;
//	while (cin >> n)        //�˴�������Ҳ������*�ȵ�
//		if (n < hexdigits.size())
//			result += hexdigits[n];
//	cout << "Your hex number is:" << result << endl;
//	return 0;
//}



#include<string>             //���ַ���ȥ��string�еı��
#include<cctype>
//int main() {
//	string s,result;
//	cout << "����һ���������ַ�����";
//
//	getline(cin, s);              //��Χfor���ϼ�
//	for (auto &c : s) {
//		if (!ispunct(c))
//			cout << c;
//	}
//	cout << endl;
//	
//
//	getline(cin, s);            //��ͳfor
//	decltype(s.size()) i = 0;
//	for (; i < s.size(); i++) {
//		if (!ispunct(s[i]))
//			result += s[i];
//	}
//	cout << typeid(i).name() << endl;
//	cout << result << endl;
//
//	return 0;
//}



//int main() {                      //ͳ��һ���ı���ff,fl,fi���ֵĴ������ɳ��Ը�дΪstring��ʽ��
//	unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
//	char ch, prech = '\0';
//	cout << "������һ���ı���" << endl;
//	while (cin >> ch) {
//		bool b1 = true;
//		if (prech == 'f') {
//			switch (ch) {
//			case 'f':
//				++ffCnt;
//				b1 = false;
//				break;
//			case 'l':
//				++flCnt;
//				break;
//			case 'i':
//				++fiCnt;
//				break;
//			}
//		}
//		if (!b1)   //������fffff...ʱ��ʵ��ÿ2��fһ��
//			prech = '\0';
//		else
//			prech = ch;     //prech��ʱ��ŵ�ǰ�ַ�
//	}
//	cout << "ff�������ǣ�" << ffCnt << endl;
//	cout << "fl�������ǣ�" << flCnt << endl;
//	cout << "fi�������ǣ�" << fiCnt << endl;
//	return 0;
//}



//��������intָ��
void SwapPointer1(int *p, int *q) {   //ֵ���ݣ�ָ���ָ����ָ���ݾ�������
	int *temp = p;
	p = q;
	q = temp;
}
void SwapPointer2(int *p, int *q) {   //����ָ����ָ����
	int temp = *p;
	*p = *q;
	*q = temp;
}
void SwapPointer3(int *&p, int *&q) {   //int *& ָ�ò�����һ�����ã����õĶ�����һ��intָ��
	int *temp = p;
	p = q;
	q = temp;
}
void SwapTest() {
	int a = 1, b = 2;
	int *p = &a, *q = &b;
	SwapPointer1(p, q);
	cout << a << b << *p << *q << endl; //1212
	a = 1, b = 2, *p = a, *q = b;
	SwapPointer2(p, q);
	cout << a << b << *p << *q << endl; //2121
	a = 1, b = 2, *p = a, *q = b;
	SwapPointer3(p, q);
	cout << a << b << *p << *q << endl; //1221
}



//����ָ����������ַ�ʽ
void print1(const int *p) {   //������ָ��߽�
	cout << *p << endl;
}
void print2(const int *p, const int sz) {   //�ɵ������ƶ�����ά��
	int i = 0;
	while (i != sz) {
		cout << *p++ << endl;
		++i;
	}
}
void print3(const int *a, const int *b) {   //��begin��end���Ʊ߽�
	for (auto p = a; p != b; ++p)
		cout << *p << endl;
}
void PointerManageTest() {
	int i = 0, j[2] = { 1,2 };
	print1(&i);
	print1(j);
	print2(&i, 1);
	print2(j, 2);
	print2(j, sizeof(j) / sizeof(*j));   //������ά��
	auto a = begin(j);
	auto b = end(j);
	print3(a, b);
}

void ArraySize()   //���ά����ά��
{
	int Array[5][5];
	int numberOfRow, numberOfCol, len;
	numberOfCol = sizeof(Array[0]) / sizeof(int);
	len = sizeof(Array) / sizeof(int);
	numberOfRow = len / numberOfCol;
}



//int main(int argc, char *argv[]) {        //��main������ʵ���������ӳ�string���
//	string str;
//	for (int i = 0; i != argc; ++i) {
//		str += argv[i];
//	}
//	cout << str << endl;
//	return 0;
//}



//int main() {      //��ʼ������
//	int a[10];
//	static int b;
//	int c;
//	cout << a[2] + 2 << endl;
//	cout << b+2  << endl;
//	cout << c << endl;   //�˴�compile����cδ��ʼ��
//}



int func1(int a, int b) {      //����ָ������ָ�룬�����浽vector��
	return a + b;
}
int func2(int a, int b) {
	return a - b;
}
int func3(int a, int b) {
	return a * b;
}
int func4(int a, int b) {
	return a / b;
}
void Compute(int a, int b, int(*p)(int, int)) {
	cout << p(a, b) << endl;
}
void PointerFcnTest() {
	int i = 5, j = 10;
	decltype(func1) *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4; //��decltype���ٱ�ʾ��������
	int(*p5)(int, int) = func1;
	int ans = p5(i, j);
	ans = (*p5)(i, j);

	//int *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
	vector<decltype(func1)* > vF = { p1,p2,p3,p4 };
	for (auto p : vF)
		Compute(i, j, p);
}



//class NoDefault {      //��NoDefualt��Ĭ�Ϲ��캯����������C��C��ǰһ���ͳ�Ա������C��Ĭ�Ϲ��캯��
//public:
//	NoDefault(int i) {
//		val = i;
//	}
//	int val;
//};
//
//class C {
//public:
//	NoDefault nd;
//	C(int i = 0) :nd(i) { };
//};
//
//int main() {
//	C c;
//	cout << c.nd.val << endl;
//}



////explicit���캯����������ֹ��ʽת���ġ��뿴����Ĵ��룺
//class Test1
//{
//public:
//	Test1(int n) { num = n; } //��ͨ���캯��
//private:
//	int num;
//};
//class Test2
//{
//public:
//	explicit Test2(int n) { num = n; } //explicit(��ʽ)���캯��
//private:
//	int num;
//};
//int main()
//{
//	Test1 t1 = 12; //��ʽ�����乹�캯��, �ɹ�
//	Test2 t2 = 12; //�������,������ʽ�����乹�캯��
//	Test2 t3(12); //��ʾ���óɹ�
//	return 0;
//}
////Test1�Ĺ��캯����һ��int�͵Ĳ�����Code19�л���ʽת���ɵ���Test1��������캯������Test2�Ĺ��캯����
////����Ϊexplicit����ʽ�������ʾ����ͨ����ʽת��������������캯������˴���20�л���ֱ������
////��ͨ���캯���ܹ�����ʽ���á���explicit���캯��ֻ�ܱ���ʾ���á�



//#include<fstream>
//using namespace std;
//#define data ("F:\\code\\c++\\Project3_Primer\\data.txt")
//
//int main() {
//	ifstream in(data);
//	if (!in) {
//		cerr << "�޷��������ļ�" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while (getline(in, line)) {
//		words.push_back(line);
//	}
//	in.close();
//	vector<string>::const_iterator it = words.begin();
//	while (it != words.end()) {
//		cout << *it << endl;
//		++it;
//	}
//	return 0;
//}



//void replace_string(string &s, const string &oldval, const string &newval) {  //��ԭ�е�string�У���oldval�滻Ϊnewval
//	auto l = oldval.size();
//	if (!l)
//		return;
//	auto iter = s.begin();
//	while (iter <= s.end() - l) {
//		auto iter1 = iter;
//		auto iter2 = oldval.begin();
//		while (iter2 != oldval.end() && *iter1 == *iter2) {
//			iter1++;
//			iter2++;
//		}
//		if (iter2 == oldval.end()) {
//			iter = s.erase(iter, iter1);
//			if (newval.size()) {
//				iter2 = newval.end();
//				do {
//					iter2--;
//					iter = s.insert(iter, *iter2);
//				} while (iter2 > newval.begin());
//			}
//			iter += newval.size();
//		}
//		else iter++;
//	}
//}

//void replace_string(string &s, const string &oldval, const string &newval) {   //ʹ���±������iteratorͨ������
//	int p = 0;                                                                 //���򵥵�ʵ��string����
//	while ((p = s.find(oldval, p)) != string::npos) {
//		s.replace(p, oldval.size(), newval);
//		p += newval.size();
//	}
//}
//
//int main() {
//	string s = "tho thru tho!";
//	replace_string(s, "thru", "through");
//	cout << s << endl;
//	replace_string(s, "tho", "though");
//	cout << s << endl;
//	replace_string(s, "through", " ");
//	cout << s << endl;
//	return 0;
//}



//void find_char(string &s, const string &chars) {
//	cout << "��" << s << "�в���" << chars << "���ַ�" << endl;
//	string::size_type pos = 0;
//	while ((pos = s.find_first_of(chars, pos)) != string::npos) {
//		cout << "pos: " << pos << ", char: " << s[pos] << endl;
//		pos++;
//	}
//}
//int main() {
//	string s = "ab2c3d7R4E6";
//	cout << "������������" << endl;
//	find_char(s, "0123456789");
//	cout << endl << "����������ĸ" << endl;
//	find_char(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
//	return 0;
//}



//int main() {      
//	vector<int> vec;
//	int i;
//	while (cin >> i)  //ʵ��
//		vec.push_back(i);
//	for (auto j = vec.begin(); j != vec.end(); j++)
//		cout << *j << endl;
//}



//#include<fstream>                       //���㷨���ݺ��������Ʋ���
//#include<algorithm>
//
//inline void output_words(vector<string> &words) {   //�������Բ���������ʽ
//	for (auto iter = words.begin(); iter != words.end(); iter++)
//		cout << *iter << " ";
//	cout << endl;
//}
//bool isShorter(const string &s1, const string &s2) {   //�˴�����Ҳ���Բ���������ʽ
//	return s1.size() < s2.size();
//}
//void elimDups(vector<string> &words) {
//	output_words(words);
//
//	sort(words.begin(), words.end());
//	output_words(words);
//
//	auto end_unique = unique(words.begin(), words.end());   //unique�㷨����words��ʹ��ÿ������ֻ����һ�Σ������ڷ�Χ��
//	output_words(words);                                    //ǰ��������ָ���ظ�����֮��һ��λ�õ�iterator
//
//	words.erase(end_unique, words.end());                   //�����Χ���ظ��ĵ���
//	output_words(words);
//
//	stable_sort(words.begin(), words.end(), isShorter);
//	output_words(words);
//}
//int main() {
//	vector<string> words;
//	string word;
//	while (cin >> word)
//		words.push_back(word);
//	elimDups(words);
//	return 0;
//}



//#include<functional>      //��ϵbind�������Ϊ��������������ʹ��
//using namespace std::placeholders;      //ռλ��_1�������ռ�
//
//bool check_size(const string &s, string::size_type sz) {
//	return s.size() <= sz;
//}
//void biggies(vector<int> &vc, const string &s) {
//	auto p = find_if(vc.begin(), vc.end(), bind(check_size, s, _1));   //���ҵ�һ�����ڵ���s���ȵ���ֵ
//	cout << "��" << p - vc.begin() + 1 << "����" << *p << "���ڵ���" << s << "�ĳ���" << endl;
//}
//int main() {
//	vector<int> vc = { 1,2,3,4,5,6,7,8,9 };
//	biggies(vc, "Hello");
//	biggies(vc, "everyone");
//	biggies(vc, "!");
//	return 0;
//}



//int main() {      //�������ظ�Ԫ��
//	vector<int> vi = { 1,2,2,3,4,5,5,6 };
//	list<int> li;
//	unique_copy(vi.begin(), vi.end(), back_inserter(li)); //unique_copy���յ���������������ʾ�������ظ�Ԫ�ص�Ŀ��λ�á�
//	for (auto v : li)      //��Χfor
//		cout << v << " ";
//	cout << endl;
//	return 0;
//}



//#include<fstream>            //����������ʹ��,���ļ��ж����ַ���
//#include<iterator>
//int main() {
//	ifstream in("F:\\code\\c++\\Project3_Primer\\data.txt");
//	if (!in) {
//		cout << "�������ļ�ʧ��" << endl;
//		exit(1);
//	}
//
//	//���������������ļ������ַ���
//	istream_iterator<string> in_iter(in);
//	//β�������
//	istream_iterator<string> eof;
//	vector<string> words;
//	while (in_iter != eof) {
//		words.push_back(*in_iter++);
//	}
//	for (auto word : words)
//		cout << word << " ";
//	cout << endl;
//}



//#include<fstream>          //pair��ϰ
//#include<utility>
//int main() {
//	vector<pair<string, int>> data;
//	string s;
//	int v;
//	while (cin >> s && cin >> v)
//		data.push_back({ s,v });
//	for (const auto &d : data)
//		cout << d.first << " " << d.second << endl;
//	return 0;
//}



//vector<int> *new_vector() {           //ֱ�ӹ���̬�ڴ�
//	return new (nothrow) vector<int>;
//}
//void read_ints(vector<int> *pv) {
//	int v;
//	while (cin >> v)
//		pv->push_back(v);
//}
//void print_ints(vector<int> *pv) {
//	for (const auto &v : *pv)
//		cout << v << " ";
//	cout << endl;
//}
//int main() {
//	vector<int> *pv = new_vector();
//	if (!pv) {
//		cout << "�ڴ治��" << endl;
//		return -1;
//	}
//	read_ints(pv);
//	print_ints(pv);
//	delete pv;
//	pv = nullptr;
//	return 0;
//}

//#include<memory>              //����ָ�����̬�ڴ�
//shared_ptr<vector<int>> new_vector() {
//	return make_shared<vector<int>>();
//}
//void read_ints(shared_ptr<vector<int>> spv) {
//	int v;
//	while (cin >> v)
//		spv->push_back(v);
//}
//void print_ints(shared_ptr<vector<int>> spv) {
//	for (const auto &v : *spv)   //�����*spv?  ����spvָ��Ķ�̬vector
//		cout << v << " ";
//	cout << endl;
//}
//int main() {
//	auto spv = new_vector();
//	read_ints(spv);
//	print_ints(spv);
//	return 0;
//}



//class Employee {               //���忽�������Ա���˴����붨�忽�����캯��������sn��һ��
//public:
//	Employee() { mysn = sn++; }
//	Employee(const string &s) {
//		name = s;
//		mysn = sn++;
//	}
//	Employee(Employee &e) {
//		name = e.name;
//		mysn = sn++;
//	}
//	Employee& operator = (Employee &rhs) {
//		name = rhs.name;
//		return *this;
//	}
//	const string &get_name() { return name; }
//	int get_mysn() { return mysn; }
//private:
//	string name;
//	int mysn;
//	static int sn;
//};
//int Employee::sn = 0;
//
//void f(Employee &s) {
//	cout << s.get_name() << ":" << s.get_mysn() << endl;
//}
//int main() {
//	Employee a("��"), b = a, c;
//	c = b;
//	f(a); f(b); f(c);
//	return 0;
//}



//decltype�ͺ궨�������
#define  GetProperty(Var,VarName) inline auto Get##VarName() const ->decltype(Var) { return Var;} // "##"Ϊ�Ǻ�ճ�ӷ�
#define  SetProperty(Var,VarName) inline void Set##VarName(decltype(Var) _v){ Var = _v;}
//#define  GetSetProperty(Var,VarName)\
//	GetProperty(Var, VarName)\  // '\'Ϊ������
//	SetProperty(Var, VarName)
#define  GetSetProperty(Var,VarName) GetProperty(Var, VarName) SetProperty(Var, VarName)

//decltype(Var) ����Varʵ�ʵ������Ƶ������� 

class Pig
{
private:
	int mAge;
	std::string mName;

public:
	GetSetProperty(mAge, Age); //һ��Ҫ�������ı���������(�е�ϰ���Եİѷ���д�����棬����������)����Ȼ���뱨��δ����mAge
	GetSetProperty(mName, Name);
};

void testDeclType()
{
	int  iarr[10] = { 0 };
	decltype(iarr) ib; //���ʱ��ib�Ķ���ȼ��� int ib[10];������һ���ģ���Ҫ��Ϊib��һ��ָ���ˣ�����һ�����ڵ����顣
	printf("--- sizeof ib:%d\n", sizeof(ib)); //40

	Pig p;
	p.SetAge(123);
	p.SetName("uuu");

	printf("--- pig age:%d, name:%s\n", p.GetAge(), p.GetName().c_str());

	/*
	--- sizeof ib:40
	--- pig age:123, name:uuu
	*/
}



template <class T>//ʹ�ú���ģ��
void sort(T a[], int size, bool(*f)(T, T)){
	bool flag;//����ð������ǰ����ð��
	int i, j;
	for (i = 1; i < size; ++i) {
		flag = false;
		for (j = 0; j < size - i; ++j)
			if (f(a[j + 1], a[j]))  //�ú���f(T,T)����ʾ�������
			{
				T tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = true;
			}
		if (!flag) break;
	}
}
//�������
bool decreaseInt(int x, int y) { return x < y; }
bool increaseString(const char *x, const char *y) { return strcmp(x, y) < 0; }
void PointerfcnTemplateTest()
{
	int a[] = { 3,1,4,2,5,8,6,7,0,9 }, i;
	const char *b[] = { "aaa","bbb","fff","ttt","hhh","ddd","ggg","www","rrr","vvv" };

	sort(a, 10, decreaseInt);
	for (i = 0; i < 10; ++i) cout << a[i] << "\t";
	cout << endl;

	sort(b, 10, increaseString);
	for (i = 0; i < 10; ++i) cout << b[i] << "\t";
	cout << endl;
}




int main() {
	PointerfcnTemplateTest();
}