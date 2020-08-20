#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>
#include<string.h>
#include<ctime>
using namespace std;

// ############ practice #########################

//#include"CMobilePhone.h"                 //自定义拷贝构造函数，实现动态内存拷贝
//int main() {
//	CMobilePhone iMp1("Motorola");
//	iMp1.ShowPhoneName();
//	CMobilePhone iMp2(iMp1);
//	iMp2.ShowPhoneName();
//	return 0;
//}


#define MAX_LEN 255                                  //字符串替换
void replace(char chString[], char chOldWorld[], char chNewWorld[])
{
	int i, nStartPos = 0, nlen1 = 0, nlen2 = 0, nlen3 = 0, nfound;
	while (chOldWorld[nlen2++] != '\0');
	nlen2--;
	while (chNewWorld[nlen3++] != '\0');         
	nlen3--;                                           
	while (chString[nStartPos] != '\0') {        
		nfound = 1;
		for(i=0;i<nlen2;i++)
			if (chString[nStartPos + i] != chOldWorld[i]) {
				nfound = 0;
				break;
			}
		if (nfound == 1) {
			while (chString[nlen1++] != '\0');
			nlen1--;
			if (nlen3 - nlen2 >= 0) {
				for (i = nlen1 - 1; i >= nStartPos; i--)
					chString[i + nlen3 - nlen2] = chString[i];
			}
			else {
				for (i = nStartPos + nlen2; i < nlen1; i++)
					chString[i + nlen3 - nlen2] = chString[i];
			}
			chString[nlen1 + nlen3 - nlen2] = '\0';
			for (i = 0; i < nlen3; i++)
				chString[nStartPos + i] = chNewWorld[i];
			nStartPos += nlen3;
		}
		else
			nStartPos++;
	}
}
//int main() {
//	char chStr[MAX_LEN], chOld[MAX_LEN], chNew[MAX_LEN];
//	cout << "输入原始字符串：";
//	gets_s(chStr);
//	cout << "输入被替换串：";
//	gets_s(chOld);
//	cout << "输入替换串:";
//	gets_s(chNew);
//	replace(chStr, chOld, chNew);
//	cout << "处理后的字符串为："<< chStr << endl;
//	return 0;
//}

//int main() {                           //fgets/ gets_s/ getline
//	char array1[255];
//	char array2[255];
//	/*string array1;*/
//	//string array1;
//	//string array2;
//	gets_s(array1);
//	fgets(array2, 255, stdin);
//	cout << array1 << endl << array2 << endl;
//	string s1, s2;
//	getline(cin, s1);
//}


//#define random(a,b) (rand()%(b-a))                   //动态内存创建多维数组
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


//int main() {                                         //动态内存字符串组操作（动态内存分配未成功）
//		int n = 0, i,j;
//		cin >> n;
//		string *ptr1 = new string[n];
//		string *ptr2 = new string[n];
//		memset(ptr1, 0x00, sizeof(string)*n);
//		memset(ptr2, 0x00, sizeof(string)*n);
//		if (ptr1 == NULL || ptr2 == NULL) exit(1);
//		for (i = 0; i < n; i++) {
//			cin >> ptr1[i];
//		}
//		for (i = 0; i < n; i++) {
//			for (j = 0; ptr1[i][j] != '\0'; j++) {
//				if (ptr1[i][j] == '0' || ptr1[i][j] == '1' || ptr1[i][j] == '2' || ptr1[i][j] == '3' || ptr1[i][j] == '4' ||
//					ptr1[i][j] == '5' || ptr1[i][j] == '6' || ptr1[i][j] == '7' || ptr1[i][j] == '8' || ptr1[i][j] == '9') {
//					ptr2[i] += ptr1[i][j];
//				}
//				else {};
//			}
//		}
//		for (i = 0; i < n; i++) {
//			cout << ptr2[i] << endl;
//		}
//		delete[] ptr1;
//		delete[] ptr2;
//		ptr1 = NULL;
//		ptr2 = NULL;
//		return 0;
//	}





//#################### course ################

#include"test.h" //外部变量与外部函数
void ex_fun();
//int main() {
//	cout << external << endl; //在test.cpp中定义为全局变量，在test.h中声明为外部变量，在中文件中包含头文件即可使用
//	ex_fun(); //在另一cpp中定义，主文件不需包含头文件，声明以后即可用
//	ex_fun_h(); //在头文件中定义的函数包含后可直接用
//}



//使用带析构语义的类的C++异常处理
class MyException {
public:
	MyException(const string &message) :message(message) {}
	~MyException() {}
	const string &getMessage() const {
		return message;
	}
private:
	string message;
};
class Demo {
public:
	Demo() {
		cout << "Constructor of Demo" << endl;
	}
	~Demo() {
		cout << "Destructor of Demo" << endl;
	}
};
void func() throw(MyException) {
	Demo d;
	cout << "Throw MyException in func()" << endl;
	throw MyException("exception thrown by func()");
}
void testException() {
	cout << "In main function" << endl;
	try {
		func();
	}   //会将从try开始到异常被抛出之间构造的所有自动对象进行析构
	catch (MyException& e) {
		cout << "Caught an exception: " << e.getMessage() << endl;
	}
	cout << "Resume the execution of main()" << endl;
}



//顺序容器的基本操作、模板
#include<iterator>
template <class T>
void printContainer(const char* msg, const T& s) {
	cout << msg << ":";
	copy(s.begin(), s.end(), ostream_iterator<int> (cout, " ")); //注意输出方式，需包含头文件<iterator>
	cout << endl;
}
#include<deque>
#include<list>
void testContainer() {
	istream_iterator<int> i1(cin), i2; //注意输入方式！ 输入0-9
	deque<int> s(i1, i2);
	printContainer("deque at first", s);
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);
	list<int>::iterator it = l.begin();
	while (it != l.end()) { //每两个元素顺序颠倒
		int v = *it;
		it = l.erase(it);
		++it;
		l.insert(it, v);
	}
	printContainer("list at last", l);
	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);
}



//多重映射multimap
//上课时间查询
#include<map>
//#include<utility>
void testMultimap() {
	multimap<string, string> courses;
	typedef multimap<string, string>::iterator CourseIter;

	courses.insert(make_pair("C++", "2-6"));
	courses.insert({ "COMPILER", "3-1" });
	courses.insert({ "COMPILER", "5-2" });
	courses.insert({ "OS", "1-2" });
	courses.insert({ "OS", "4-1" });
	courses.insert({ "OS", "5-5" });

	string name;
	int count;
	do {
		cin >> name; //输入Java和OS
		count = courses.count(name);
		if (count == 0)
			cout << "Cannot find this course!" << endl;
	} while (count == 0);
	cout << count << " lesson(s) per week: ";
	pair<CourseIter, CourseIter> range = courses.equal_range(name); //multimap的循环方法
	for (CourseIter it = range.first; it != range.second; ++it) {
		cout << it->second << " ";
	}
	cout << endl;
}



#include<fstream>  //流类库
#define ADDRESS1 ("F:\\Code\\code\\Practice_and_course\\in.txt")
#define ADDRESS2 ("F:\\Code\\code\\Practice_and_course\\out.txt")
void testIOstream() {
	ifstream in(ADDRESS1, ios::in);
	string s;
	getline(in, s);
	cout << s << endl;
	in.close();

	//ofstream out(ADDRESS2, ios::out);
	//out << "this file is used to save fstream operations: " << endl;
	//out << s << endl;

	//ofstream out(ADDRESS2, ios::out);
	//out << "ios::out mode will discard existing data!" << endl;

	ofstream out(ADDRESS2, ios::app);
	out << "ios::app mode will locate to the end of file." << endl;

	out.close();
}












#include"bank.h"
int main() {
	testBankAccount();
}