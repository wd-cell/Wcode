#include<iostream>
#include"Phone.h"
using namespace std;

void CMobiePhone::SetPhoneName() {
	cout << "�����ֻ�����";
	cin >> m_strPhoneName;
};
void CMobiePhone::SetPhoneType() {
	cout << "�����ֻ��ͺţ�";
	cin >> m_strPhoneType;
};
void CMobiePhone::SetPhoneSize() {
	cout << "�����ֻ��ߴ磺";
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