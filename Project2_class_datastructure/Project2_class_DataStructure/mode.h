#pragma once
/*
** FileName     : SingletonPatternDemo1
** Author       : Jelly Young
** Date         : 2013/11/20
** Description  : More information, please go to http://www.jellythink.com
*/

#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (m_Instance == NULL)
		{
			m_Instance = new Singleton();
		}
		return m_Instance;
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	// This is just a operation example
	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton() { m_Test = 10; }
	static Singleton *m_Instance;
	int m_Test;
};

Singleton *Singleton::m_Instance = NULL;

//int main(int argc, char *argv[])
//{
//	Singleton *singletonObj = Singleton::GetInstance();
//	cout << singletonObj->GetTest() << endl;
//
//	Singleton::DestoryInstance();
//	return 0;
//}





#include <iostream>
using namespace std;

enum CarType { BENZ, BMW };

class Car//����
{
public:
	virtual void createdCar(void) = 0;
};

class BenzCar : public Car //���۳�
{
public:
	BenzCar()
	{
		cout << "Benz::Benz()" << endl;
	}
	virtual void createdCar(void)
	{
		cout << "BenzCar::createdCar()" << endl;
	}
	~BenzCar()
	{

	}
};

class BmwCar : public Car //����
{
public:
	BmwCar()
	{
		cout << "Bmw::Bmw()" << endl;
	}
	virtual void createdCar(void)
	{
		cout << "BmwCar::createdCar()" << endl;
	}
};


class CarFactory //����
{
public:
	Car* createSpecificCar(CarType type)
	{
		switch (type)
		{
		case BENZ://�������۳�
			return (new BenzCar());
			break;
		case BMW://��������
			return (new BmwCar());
			break;
		default:
			return NULL;
			break;
		}
	}
};

//int main(int argc, char** argv)
//{
//	CarFactory carfac;
//	Car* specificCarA = carfac.createSpecificCar(BENZ);//���������ڶ�ʾ����new��û��delete���о������ر��Ͻ�
//	Car* specificCarB = carfac.createSpecificCar(BMW);
//
//	delete specificCarA; delete specificCarB;
//
//	return 0;
//}