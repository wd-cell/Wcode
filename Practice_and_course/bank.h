#pragma once
//####################�����˻�ʵ��#############################
#include<string>
using namespace std;

//date.h
class Date //������
{
private:
	int year;
	int month;
	int day;
	int totalDays; //�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���

public:
	Date(int year, int month, int day);
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const; //��õ����ж�����
	bool isLeapYear() const { //�жϵ����Ƿ�Ϊ����
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show() const; //�����ǰ����
	int operator - (const Date& date) const {
		return totalDays - date.totalDays;
	}
};

//accumulator.h
class Accumulator { //��ĳ����ֵ�����ۼ�
private:
	Date lastDate; //�ϴα����ֵ������
	double value;  //��ֵ�ĵ�ǰֵ
	double sum;    //��ֵ�����ۼ�֮��

public:
	Accumulator(const Date& date, double value) :lastDate(date), value(value), sum(0) { } //dateΪ��ʼ�ۼӵ�����
	double getSum(const Date& date) const { //��õ�����date���ۼӽ��
		return sum + value * (date - lastDate);
	}
	void change(const Date& date, double value) { //��date����ֵ���Ϊvalue
		sum = getSum(date);
		lastDate = date;
		this->value = value;
	}
	void reset(const Date& date, double value) { //��ʼ���������ڱ�Ϊdate����ֵ��Ϊvalue���ۼ�������
		lastDate = date;
		this->value = value;
		sum = 0;
	}
};

//account.h
class Account { //�˻���
private:
	string id; //�˺�
	double balance; //���
	static double total; //�����˻����ܽ��

protected:
	Account(const Date& date, const string& id); //����������õĹ��캯��
	void record(const Date& date, double amount, const string& desc); //��¼һ���ˣ�amountΪ��descΪ˵��
	void error(const string& msg) const;

public:
	const string& getID() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	virtual void deposit(const Date& date, double amount, const string& desc) = 0; //�����ֽ�
	virtual void withdraw(const Date& date, double amount, const string& desc) = 0; //ȡ���ֽ�
	virtual void settle(const Date& date) = 0; //���㣨������Ϣ����ѵȣ���ÿ�½���һ�Σ�dateΪ��������
	virtual void show() const;
};

class SavingsAccount :public Account { //�����˻���
private:
	Accumulator acc; //����������Ϣ���ۼ���
	double rate; //����������

public:
	SavingsAccount(const Date& date, const string& id, double rate);
	double getRate() const { return rate; }
	void deposit(const Date& date, double amount, const string& desc); //�����ֽ�
	void withdraw(const Date& date, double amount, const string& desc); //ȡ���ֽ�
	void settle(const Date& date); //������Ϣ��ÿ��1��1�յ���һ��
};

class CreditAccount :public Account { //�����˻���
private:
	Accumulator acc; //����������Ϣ���ۼ���
	double credit; //���ö��
	double rate; //Ƿ���������
	double fee; //���ÿ����
	double getDebt() const { //���Ƿ���
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}

public:
	CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const { //��ÿ�������
		if (getBalance() < 0)
			return credit + getBalance();
		else
			return credit;
	}
	void deposit(const Date& date, double amount, const string& desc); //�����ֽ�
	void withdraw(const Date& date, double amount, const string& desc); //ȡ���ֽ�
	void settle(const Date& date); //������Ϣ����ѣ�ÿ��1��1�յ���һ��
	void show() const;
};