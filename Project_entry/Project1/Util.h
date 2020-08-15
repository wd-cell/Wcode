#pragma once
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
using namespace std;

class Util
{
public:
	Util();
	~Util();

	static string& Tolower(string &s) {             //将字符串转换为小写字符
		transform(s.begin(), s.end(), s.begin(), tolower);      //相当于for_each,   tolower,toupper在cctype中
		return s;
	}
	static void display(const string &s) {         //显示字符串
		cout << s << " ";
	}
	static char getInitial(const string &s) {      //首字符大写
		return toupper(s[0]);
	}
	static bool isNullString(const string &str) {   //判断字符串是否为空（空格、tab键、换行符等）
		string strCopy = str;
		strCopy.erase(remove_if(strCopy.begin(), strCopy.end(), isspace), strCopy.end());
		return strCopy.empty();
	}
};

