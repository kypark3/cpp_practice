#include "cpp_proj_BankingCommonDecl.h"
#include "cpp_proj_Account.h"

Account::Account(const char name[], int balance, int ID) : ID(ID), balance(balance) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account &account) : balance(account.balance), ID(account.ID) {
	name = new char[strlen(account.name) + 1];
	strcpy(name, account.name);
}

int Account::getBalance() const {
	return balance;
}

void Account::outMoney(int out_money) {
	balance -= out_money;
}

void Account::inMoney(int in_money) {
	balance += in_money;
}

int Account::getAccountID() const {
	return ID;
}

void Account::showAccountInfo() const {
	cout << "ÀÌ   ¸§ : " << name << endl;
	cout << "ÀÜ   ¾× : " << balance << endl;
	cout << "°èÁÂ ID : " << ID << endl;
}

Account::~Account() {
	cout << "delete account name" << endl;
	delete[]name;
}
