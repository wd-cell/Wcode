//#include"Ccomplex.h"
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//Ccomplex::~Ccomplex(){}
//Ccomplex operator +(Ccomplex c1, Ccomplex c2) {
//	return Ccomplex(c1.real + c2.real, c1.imag + c2.imag);
//}
//Ccomplex operator -(Ccomplex c1, Ccomplex c2) {
//	return Ccomplex(c1.real - c2.real, c1.imag - c2.imag);
//}
//Ccomplex& Ccomplex::operator ++() {
//	real = (long)(real)+1;
//	imag = (long)(real)+1;
//	return *this;
//}
//Ccomplex Ccomplex::operator ++(int) {
//	Ccomplex temp(*this);
//	real = (long)(real)+1;
//	imag = (long)(real)+1;
//	return temp;
//}
//void Ccomplex::ShowComplex(Ccomplex c) {
//	cout << "(" << c.real << "," << c.imag << "i)" << endl;
//}