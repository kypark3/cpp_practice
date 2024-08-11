#include "cpp_proj_BankingCommonDecl.h"
#include "cpp_proj_Account.h"
#include "cpp_String.h"

Account::Account(String name, int balance, int ID) : ID(ID), balance(balance) {
	this->name = name;
}

Account::Account(Account &account) : balance(account.balance), ID(account.ID) {
	this->name = account.name;
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
}
