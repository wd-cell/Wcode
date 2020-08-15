#pragma once
#include<string>
using namespace std;
class CMobiePhone {
private:
	string m_strPhoneName;
	string m_strPhoneType;
	float m_fLength, m_fWidth, m_fHeight;
public:
	void SetPhoneName();
	void SetPhoneType();
	void SetPhoneSize();
	void ShowPhoneName();
	void ShowPhoneType();
	void ShowPhoneSize();
};

