#ifndef __CPP_PROJ__
#define __CPP_PROJ__
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

class Account {
private:
	char *name; // ÀÌ¸§
	int balance; // ÀÜ¾×
	int ID; // °í°´ ID
	int account_num;

public:
	Account(const char name[], int balance, int ID, int account_num);
	~Account();

	void showAccountInfo() const;
	int getAccountID() const;
	int getBalance() const;
	void inMoney(int in_money);
	void outMoney(int out_money);
	
};

int Account::getBalance() const {
	return balance;
}

void Account::outMoney(int out_money) {
	balance -= out_money;
}

void Account::inMoney(int in_money) {
	balance += in_money;
}

int Account::getAccountID() const{
	return ID;
}

void Account::showAccountInfo () const {
	cout << "ÀÌ   ¸§ : " << name << endl;
	cout << "ÀÜ   ¾× : "<< balance << endl;
	cout << "°èÁÂ ID : " << ID << endl;
}

Account::Account(const char name[], int balance, int ID, int account_num) :balance(balance) , ID(ID), account_num(account_num){
	int name_len = strlen(name) + 1;
	this->name = new char[name_len];
	strcpy(this->name, name);
}

Account::~Account() {
	cout << "delete Account" << endl;
	delete[]name;
}



#endif // __CPP_PROJ__

