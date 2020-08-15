#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

using namespace std;//求值连续出现的个数
//int main() {
//	int currval = 0, val ;//定义于任何函数体外部的变量被初始化为0,此处不被初始化，即val是未定义的
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



#include<typeinfo>      //typeid().name输返回类型
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



#include<string>            //getline与普通cin对比，前者保留空白符整行输出，后者每隔一个空白符输出
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



#include<string>      //15位以下的dec转hex
//int main() {
//	const string hexdigits = "0123456789ABCDEF";
//	cout << "Enter a series of numbers betweem 0 and 15"
//		<< "separated by spaces. Hit ENTER when finished:"
//		<< endl;
//	string result;
//	string::size_type n;
//	while (cin >> n)        //此处结束符也可以是*等等
//		if (n < hexdigits.size())
//			result += hexdigits[n];
//	cout << "Your hex number is:" << result << endl;
//	return 0;
//}



#include<string>             //两种方法去除string中的标点
#include<cctype>
//int main() {
//	string s,result;
//	cout << "输入一个带标点的字符串：";
//
//	getline(cin, s);              //范围for，较简单
//	for (auto &c : s) {
//		if (!ispunct(c))
//			cout << c;
//	}
//	cout << endl;
//	
//
//	getline(cin, s);            //传统for
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



//int main() {                      //统计一段文本中ff,fl,fi出现的次数（可尝试改写为string格式）
//	unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
//	char ch, prech = '\0';
//	cout << "请输入一段文本：" << endl;
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
//		if (!b1)   //当出现fffff...时，实现每2个f一组
//			prech = '\0';
//		else
//			prech = ch;     //prech临时存放当前字符
//	}
//	cout << "ff的数量是：" << ffCnt << endl;
//	cout << "fl的数量是：" << flCnt << endl;
//	cout << "fi的数量是：" << fiCnt << endl;
//	return 0;
//}



//交换两个int指针
void SwapPointer1(int *p, int *q) {   //值传递，指针和指针所指内容均不交换
	int *temp = p;
	p = q;
	q = temp;
}
void SwapPointer2(int *p, int *q) {   //交换指针所指内容
	int temp = *p;
	*p = *q;
	*q = temp;
}
void SwapPointer3(int *&p, int *&q) {   //int *& 指该参数是一个引用，引用的对象是一个int指针
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



//管理指针参数的三种方式
void print1(const int *p) {   //不控制指针边界
	cout << *p << endl;
}
void print2(const int *p, const int sz) {   //由调用者制定数组维度
	int i = 0;
	while (i != sz) {
		cout << *p++ << endl;
		++i;
	}
}
void print3(const int *a, const int *b) {   //用begin和end限制边界
	for (auto p = a; p != b; ++p)
		cout << *p << endl;
}
void PointerManageTest() {
	int i = 0, j[2] = { 1,2 };
	print1(&i);
	print1(j);
	print2(&i, 1);
	print2(j, 2);
	print2(j, sizeof(j) / sizeof(*j));   //求数组维度
	auto a = begin(j);
	auto b = end(j);
	print3(a, b);
}

void ArraySize()   //求二维数组维度
{
	int Array[5][5];
	int numberOfRow, numberOfCol, len;
	numberOfCol = sizeof(Array[0]) / sizeof(int);
	len = sizeof(Array) / sizeof(int);
	numberOfRow = len / numberOfCol;
}



//int main(int argc, char *argv[]) {        //将main函数的实参内容连接成string输出
//	string str;
//	for (int i = 0; i != argc; ++i) {
//		str += argv[i];
//	}
//	cout << str << endl;
//	return 0;
//}



//int main() {      //初始化问题
//	int a[10];
//	static int b;
//	int c;
//	cout << a[2] + 2 << endl;
//	cout << b+2  << endl;
//	cout << c << endl;   //此处compile错误，c未初始化
//}



int func1(int a, int b) {      //创建指向函数的指针，并保存到vector中
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
	decltype(func1) *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4; //用decltype快速表示函数类型
	int(*p5)(int, int) = func1;
	int ans = p5(i, j);
	ans = (*p5)(i, j);

	//int *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
	vector<decltype(func1)* > vF = { p1,p2,p3,p4 };
	for (auto p : vF)
		Compute(i, j, p);
}



//class NoDefault {      //类NoDefualt无默认构造函数，定义类C，C有前一类型成员，定义C的默认构造函数
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



////explicit构造函数是用来防止隐式转换的。请看下面的代码：
//class Test1
//{
//public:
//	Test1(int n) { num = n; } //普通构造函数
//private:
//	int num;
//};
//class Test2
//{
//public:
//	explicit Test2(int n) { num = n; } //explicit(显式)构造函数
//private:
//	int num;
//};
//int main()
//{
//	Test1 t1 = 12; //隐式调用其构造函数, 成功
//	Test2 t2 = 12; //编译错误,不能隐式调用其构造函数
//	Test2 t3(12); //显示调用成功
//	return 0;
//}
////Test1的构造函数带一个int型的参数，Code19行会隐式转换成调用Test1的这个构造函数。而Test2的构造函数被
////声明为explicit（显式），这表示不能通过隐式转换来调用这个构造函数，因此代码20行会出现编译错误。
////普通构造函数能够被隐式调用。而explicit构造函数只能被显示调用。



//#include<fstream>
//using namespace std;
//#define data ("F:\\code\\c++\\Project3_Primer\\data.txt")
//
//int main() {
//	ifstream in(data);
//	if (!in) {
//		cerr << "无法打开输入文件" << endl;
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



//void replace_string(string &s, const string &oldval, const string &newval) {  //在原有的string中，将oldval替换为newval
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

//void replace_string(string &s, const string &oldval, const string &newval) {   //使用下标而不是iterator通常可以
//	int p = 0;                                                                 //更简单地实现string操作
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
//	cout << "在" << s << "中查找" << chars << "中字符" << endl;
//	string::size_type pos = 0;
//	while ((pos = s.find_first_of(chars, pos)) != string::npos) {
//		cout << "pos: " << pos << ", char: " << s[pos] << endl;
//		pos++;
//	}
//}
//int main() {
//	string s = "ab2c3d7R4E6";
//	cout << "查找所有数字" << endl;
//	find_char(s, "0123456789");
//	cout << endl << "查找所有字母" << endl;
//	find_char(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
//	return 0;
//}



//int main() {      
//	vector<int> vec;
//	int i;
//	while (cin >> i)  //实验
//		vec.push_back(i);
//	for (auto j = vec.begin(); j != vec.end(); j++)
//		cout << *j << endl;
//}



//#include<fstream>                       //向算法传递函数，定制操作
//#include<algorithm>
//
//inline void output_words(vector<string> &words) {   //参数可以不用引用形式
//	for (auto iter = words.begin(); iter != words.end(); iter++)
//		cout << *iter << " ";
//	cout << endl;
//}
//bool isShorter(const string &s1, const string &s2) {   //此处参数也可以不用引用形式
//	return s1.size() < s2.size();
//}
//void elimDups(vector<string> &words) {
//	output_words(words);
//
//	sort(words.begin(), words.end());
//	output_words(words);
//
//	auto end_unique = unique(words.begin(), words.end());   //unique算法重排words，使得每个单词只出现一次，排列在范围的
//	output_words(words);                                    //前部，返回指向不重复区域之后一个位置的iterator
//
//	words.erase(end_unique, words.end());                   //清楚范围后部重复的单词
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



//#include<functional>      //联系bind（可理解为函数适配器）的使用
//using namespace std::placeholders;      //占位符_1的命名空间
//
//bool check_size(const string &s, string::size_type sz) {
//	return s.size() <= sz;
//}
//void biggies(vector<int> &vc, const string &s) {
//	auto p = find_if(vc.begin(), vc.end(), bind(check_size, s, _1));   //查找第一个大于等于s长度的数值
//	cout << "第" << p - vc.begin() + 1 << "个数" << *p << "大于等于" << s << "的长度" << endl;
//}
//int main() {
//	vector<int> vc = { 1,2,3,4,5,6,7,8,9 };
//	biggies(vc, "Hello");
//	biggies(vc, "everyone");
//	biggies(vc, "!");
//	return 0;
//}



//int main() {      //拷贝不重复元素
//	vector<int> vi = { 1,2,2,3,4,5,5,6 };
//	list<int> li;
//	unique_copy(vi.begin(), vi.end(), back_inserter(li)); //unique_copy接收第三个迭代器，表示拷贝不重复元素的目的位置。
//	for (auto v : li)      //范围for
//		cout << v << " ";
//	cout << endl;
//	return 0;
//}



//#include<fstream>            //流迭代器的使用,从文件中读入字符串
//#include<iterator>
//int main() {
//	ifstream in("F:\\code\\c++\\Project3_Primer\\data.txt");
//	if (!in) {
//		cout << "打开输入文件失败" << endl;
//		exit(1);
//	}
//
//	//创建流迭代器从文件读入字符串
//	istream_iterator<string> in_iter(in);
//	//尾后迭代器
//	istream_iterator<string> eof;
//	vector<string> words;
//	while (in_iter != eof) {
//		words.push_back(*in_iter++);
//	}
//	for (auto word : words)
//		cout << word << " ";
//	cout << endl;
//}



//#include<fstream>          //pair练习
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



//vector<int> *new_vector() {           //直接管理动态内存
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
//		cout << "内存不足" << endl;
//		return -1;
//	}
//	read_ints(pv);
//	print_ints(pv);
//	delete pv;
//	pv = nullptr;
//	return 0;
//}

//#include<memory>              //智能指针管理动态内存
//shared_ptr<vector<int>> new_vector() {
//	return make_shared<vector<int>>();
//}
//void read_ints(shared_ptr<vector<int>> spv) {
//	int v;
//	while (cin >> v)
//		spv->push_back(v);
//}
//void print_ints(shared_ptr<vector<int>> spv) {
//	for (const auto &v : *spv)   //这里的*spv?  遍历spv指向的动态vector
//		cout << v << " ";
//	cout << endl;
//}
//int main() {
//	auto spv = new_vector();
//	read_ints(spv);
//	print_ints(spv);
//	return 0;
//}



//class Employee {               //定义拷贝构造成员，此处必须定义拷贝构造函数，否则sn会一致
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
//	Employee a("赵"), b = a, c;
//	c = b;
//	f(a); f(b); f(c);
//	return 0;
//}



//decltype和宏定义的巧用
#define  GetProperty(Var,VarName) inline auto Get##VarName() const ->decltype(Var) { return Var;} // "##"为记号粘接符
#define  SetProperty(Var,VarName) inline void Set##VarName(decltype(Var) _v){ Var = _v;}
//#define  GetSetProperty(Var,VarName)\
//	GetProperty(Var, VarName)\  // '\'为继续符
//	SetProperty(Var, VarName)
#define  GetSetProperty(Var,VarName) GetProperty(Var, VarName) SetProperty(Var, VarName)

//decltype(Var) 根据Var实际的类型推导出类型 

class Pig
{
private:
	int mAge;
	std::string mName;

public:
	GetSetProperty(mAge, Age); //一定要在声明的变量名下面(有点习惯性的把方法写在上面，变量在下面)，不然编译报错，未定义mAge
	GetSetProperty(mName, Name);
};

void testDeclType()
{
	int  iarr[10] = { 0 };
	decltype(iarr) ib; //这个时候ib的定义等价于 int ib[10];两者是一样的，不要认为ib是一个指针了，它是一个正宗的数组。
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



template <class T>//使用函数模板
void sort(T a[], int size, bool(*f)(T, T)){
	bool flag;//用于冒泡中提前结束冒泡
	int i, j;
	for (i = 1; i < size; ++i) {
		flag = false;
		for (j = 0; j < size - i; ++j)
			if (f(a[j + 1], a[j]))  //用函数f(T,T)来表示排序规则
			{
				T tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = true;
			}
		if (!flag) break;
	}
}
//排序规则
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