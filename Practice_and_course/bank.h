#pragma once
//####################银行账户实例#############################
#include<string>
using namespace std;

//date.h
class Date //日期类
{
private:
	int year;
	int month;
	int day;
	int totalDays; //该日期是从公元元年1月1日开始的第几天

public:
	Date(int year, int month, int day);
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const; //获得当月有多少天
	bool isLeapYear() const { //判断当年是否为闰年
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show() const; //输出当前日期
	int operator - (const Date& date) const {
		return totalDays - date.totalDays;
	}
};

//accumulator.h
class Accumulator { //将某个数值按日累加
private:
	Date lastDate; //上次变更数值的日期
	double value;  //数值的当前值
	double sum;    //数值按日累加之和

public:
	Accumulator(const Date& date, double value) :lastDate(date), value(value), sum(0) { } //date为开始累加的日期
	double getSum(const Date& date) const { //获得到日期date的累加结果
		return sum + value * (date - lastDate);
	}
	void change(const Date& date, double value) { //在date将数值变更为value
		sum = getSum(date);
		lastDate = date;
		this->value = value;
	}
	void reset(const Date& date, double value) { //初始化，将日期变为date，数值变为value，累加器清零
		lastDate = date;
		this->value = value;
		sum = 0;
	}
};

//account.h
class Account { //账户类
private:
	string id; //账号
	double balance; //余额
	static double total; //所有账户的总金额

protected:
	Account(const Date& date, const string& id); //供派生类调用的构造函数。不允许派生类以外的代码构造Account对象
	void record(const Date& date, double amount, const string& desc); //记录一笔账，amount为金额，desc为说明
	void error(const string& msg) const;

public:
	const string& getID() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	virtual void deposit(const Date& date, double amount, const string& desc) = 0; //存入现金
	virtual void withdraw(const Date& date, double amount, const string& desc) = 0; //取出现金
	virtual void settle(const Date& date) = 0; //结算（计算利息、年费等），每月结算一次，date为结算日期
	virtual void show() const; //显示余额
};

class SavingsAccount :public Account { //储蓄账户类
private:
	Accumulator acc; //辅助计算利息的累加器
	double rate; //存款的年利率

public:
	SavingsAccount(const Date& date, const string& id, double rate);
	double getRate() const { return rate; }
	void deposit(const Date& date, double amount, const string& desc); //存入现金
	void withdraw(const Date& date, double amount, const string& desc); //取出现金
	void settle(const Date& date); //结算利息，每年1月1日调用一次
};

class CreditAccount :public Account { //信用账户类
private:
	Accumulator acc; //辅助计算利息的累加器
	double credit; //信用额度
	double rate; //欠款的日利率
	double fee; //信用卡年费
	double getDebt() const { //获得欠款额
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}

public:
	CreditAccount(const Date& date, const string& id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const { //获得可用信用
		if (getBalance() < 0)
			return credit + getBalance();
		else
			return credit;
	}
	void deposit(const Date& date, double amount, const string& desc); //存入现金
	void withdraw(const Date& date, double amount, const string& desc); //取出现金
	void settle(const Date& date); //结算利息和年费，每年1月1日调用一次
	void show() const;
};

void testBankAccount(); //测试