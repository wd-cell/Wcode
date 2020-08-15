#pragma once
//base1.h
#include<iostream>
#include"cbase.h"
using namespace std;
class cBase1 :public cBase {
public:
	cBase1();
	virtual ~cBase1();
	void display() { cout << "Base1::display()" << endl; }
};
