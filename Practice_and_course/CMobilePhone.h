#pragma once
#include<string>
using namespace std;

class CMobilePhone {
public:
	CMobilePhone(string strPhoneName);
	CMobilePhone(CMobilePhone &iMp);
	virtual ~CMobilePhone();
	void ShowPhoneName() const;
private:
	string *m_pstrPhoneName;
};