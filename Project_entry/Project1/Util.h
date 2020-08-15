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

	static string& Tolower(string &s) {             //���ַ���ת��ΪСд�ַ�
		transform(s.begin(), s.end(), s.begin(), tolower);      //�൱��for_each,   tolower,toupper��cctype��
		return s;
	}
	static void display(const string &s) {         //��ʾ�ַ���
		cout << s << " ";
	}
	static char getInitial(const string &s) {      //���ַ���д
		return toupper(s[0]);
	}
	static bool isNullString(const string &str) {   //�ж��ַ����Ƿ�Ϊ�գ��ո�tab�������з��ȣ�
		string strCopy = str;
		strCopy.erase(remove_if(strCopy.begin(), strCopy.end(), isspace), strCopy.end());
		return strCopy.empty();
	}
};

