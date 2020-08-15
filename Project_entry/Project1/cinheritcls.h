#pragma once
//cinheritcls.h
#include<iostream>
//#include"cbase.h"
#include"cbase1.h"
using namespace std;
class cInheritcls :public cBase1 {
public:
	cInheritcls();
	virtual~cInheritcls();
	void display() { cout << "cInheritcls::display()" << endl; }
};
