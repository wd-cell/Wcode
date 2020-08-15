#include<iostream>
#include"CMobilePhone.h"
using namespace std;

CMobilePhone::CMobilePhone(string strPhoneName) {
	m_pstrPhoneName = new string;
	*m_pstrPhoneName = strPhoneName;
}
CMobilePhone::CMobilePhone(CMobilePhone &iMp) {
	m_pstrPhoneName = new string;
	*m_pstrPhoneName = *iMp.m_pstrPhoneName;
}
CMobilePhone::~CMobilePhone() {
	delete m_pstrPhoneName;
	m_pstrPhoneName = NULL;
}
void CMobilePhone::ShowPhoneName() const {
	cout << *m_pstrPhoneName << endl;
}