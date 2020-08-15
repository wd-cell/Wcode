//########################银行账户实例#############################
#include"bank.h"
#include<iostream>
using namespace std;

//namespace {
	const int DAYS_BEFOR_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
//}

//date.cpp
Date::Date(int year, int month, int day) :year(year), month(month), day(day) {
	if (day <= 0 || day > getMaxDay()) {
		cout << "Invalid date: ";
		show();
		cout << endl;
		exit(1);
	}
	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFOR_MONTH[month - 1] + day;
	if (isLeapYear() && month > 2)
		totalDays++;
}
int Date::getMaxDay() const {
	if (isLeapYear() && month == 2)
		return 29;
	else
		return DAYS_BEFOR_MONTH[month] - DAYS_BEFOR_MONTH[month - 1];
}
void Date::show() const {
	cout << getYear() << "-" << getMonth() << "-" << getDay();
}


//acount.cpp
double Account::total = 0;
Account::Account(const Date& date, const string& id) :id(id), balance(0) {
	date.show();
	cout << "\t#" << id << " created" << endl;
}
void Account::record(const Date& date, double amount, const string& desc) {
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}
void Account::error(const string& msg) const {
	cout << "Error(#" << id << ")" << msg << endl;
}
void Account::show() const {
	cout << id << "\tBalance: " << balance;
}


//SavingsAccount.cpp
SavingsAccount::SavingsAccount(const Date& date, const string& id, double rate) :Account(date, id), rate(rate), acc(date, 0) { }
void SavingsAccount::deposit(const Date& date, double amount, const string& desc) {
	record(date, amount, desc);
	acc.change(date, getBalance());
}
void SavingsAccount::withdraw(const Date& date, double amount, const string& desc) {
	if (amount > getBalance()) {
		error("not enough money");
	}
	else {
		record(date, -amount, desc);
		acc.change(date, getBalance());
	}
}
void SavingsAccount::settle(const Date& date) {
	if (date.getMonth() == 1) {
		double interest = acc.getSum(date)*rate / (date - Date(date.getYear() - 1, 1, 1));
		if (interest == 0)
			record(date, interest, "interest");
		acc.reset(date, getBalance());
	}
}


//CreditAccount.cpp
CreditAccount::CreditAccount(const Date& date, const string& id, double credit, double rate, double fee) :
	Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) {}
void CreditAccount::deposit(const Date& date, double amount, const string& desc) {
	record(date, amount, desc);
	acc.change(date, getDebt());
}
void CreditAccount::withdraw(const Date& date, double amount, const string& desc) {
	if (amount - getBalance() > credit)
		error("not enough credit");
	else {
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
}
void CreditAccount::settle(const Date& date) {
	double interest = acc.getSum(date) * rate;
	if (interest != 0)
		record(date, interest, "interest");
	if (date.getMonth() == 1)
		record(date, -fee, "annual fee");
	acc.reset(date, getDebt());
}
void CreditAccount::show() const {
	Account::show();
	cout << "\tAvailiable credit: " << getAvailableCredit();
}


//实例
void testBankAccount() { //测试用例还要一遍遍输，也体现了自动测试的意义
	Date date(2008, 11, 1); //起始日期
	SavingsAccount sa1(date, "S_3755215", 0.015);
	SavingsAccount sa2(date, "S_2361882", 0.015);
	CreditAccount ca(date, "C_5392396", 10000, 0.0005, 50);
	Account* accounts[] = { &sa1,&sa2,&ca };
	const int n = sizeof(accounts) / sizeof(Account*);
	cout << "(d)deposit  (w)withdraw  (s)show  (c)change day  (n)next month  (e)exit" << endl;
	char cmd;
	do {
		date.show(); //显示日期和总金额
		cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";
		int index, day;
		double amount;
		string desc;
		cin >> cmd;
		switch (cmd) {
		case 'd':
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->deposit(date, amount, desc);
			break;
		case 'w':
			cin >> index >> amount;
			getline(cin, desc);
			accounts[index]->withdraw(date, amount, desc);
			break;
		case 's':
			for (int i = 0; i < n; ++i) {
				cout << "[" << i << "]";
				accounts[i]->show();
				cout << endl;
			}
			break;
		case 'c':
			cin >> day;
			if (day < date.getDay())
				cout << "You cannot specify a previous day";
			else if (day > date.getMaxDay())
				cout << "Invalid day";
			else
				date = Date(date.getYear(), date.getMonth(), day);
			break;
		case 'n':
			if (date.getMonth() == 12)
				date = Date(date.getYear() + 1, 1, 1);
			else
				date = Date(date.getYear(), date.getMonth() + 1, 1);
			for (int i = 0; i < n; ++i)
				accounts[i]->settle(date);
			break;
		}
	} while (cmd != 'e');

}
