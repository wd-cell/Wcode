#pragma once
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
using namespace std;

//void bubblesort(int*h, int len) {
//	int i, j;
//	bool flag = true;
//	for (i=0; i < len && flag; ++i) {
//		flag = false;
//		for (j = len - 2; j >= 0; --j) {
//			if (h[j] > h[j + 1]) {
//				swap(h[j], h[j + 1]);
//				flag = true;
//			}
//		}
//	}
//}
//
//void selectsort(int *h, int len) {
//	int i;
//	for (i = 0; i < len - 1; ++i) {
//		int minnum = i;
//		for (int j = i; j >= 0; --j) {
//			if (h[j] < h[minnum]) {
//				minnum = j;
//				swap(h[j], h[minnum]);
//			}
//		}
//	}
//}



class Base {
public:
	Base() {
		Function();
		//a = new Base;
	}
	virtual void Function() {
		cout << "Base.function" << endl;
	}
	~Base() {
		cout << "~Base" << endl;
		//delete a;
	}

	//Base* a;
};

class A :public Base {
public:
	A() {
		Function();
	}
	virtual void Function() {
		cout << "A.function" << endl;
	}
};