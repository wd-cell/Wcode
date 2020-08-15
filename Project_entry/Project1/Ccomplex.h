#pragma once
#include<cmath>
using namespace std;

class Ccomplex {
public:
	Ccomplex(double pr = 0.0, double pi = 0.0) {  real = pr;  imag = pi; };
	virtual ~Ccomplex();
	Ccomplex operator +(Ccomplex c);
	Ccomplex operator -(Ccomplex c);
	Ccomplex& operator ++();
	Ccomplex operator ++(int);
	static void ShowComplex(Ccomplex c);
private:
	double real;
	double imag;
};