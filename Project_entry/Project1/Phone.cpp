#include<iostream>
#include"Phone.h"
using namespace std;

void CMobiePhone::SetPhoneName() {
	cout << "输入手机名：";
	cin >> m_strPhoneName;
};
void CMobiePhone::SetPhoneType() {
	cout << "输入手机型号：";
	cin >> m_strPhoneType;
};
void CMobiePhone::SetPhoneSize() {
	cout << "输入手机尺寸：";
	cin >> m_fLength >> m_fWidth >> m_fHeight;
};
void CMobiePhone::ShowPhoneName() {
	cout << m_strPhoneName << endl;
};
void CMobiePhone::ShowPhoneType() {
	cout << m_strPhoneType << endl;
};
void CMobiePhone::ShowPhoneSize() {
	cout << "The phone size is:" << m_fLength << "x" << m_fWidth << "x" << m_fHeight << endl;
};