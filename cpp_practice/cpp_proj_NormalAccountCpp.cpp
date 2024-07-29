#include "cpp_proj_BankingCommonDecl.h"
#include "cpp_proj_NormalAccount.h"

NormalAccount::NormalAccount(const char name[], int balance, int ID, int interest)
	: Account(name, balance, ID), interest(interest) { }

void NormalAccount::showAccountInfo() const {
	Account::showAccountInfo();
	cout << "������ : " << interest << endl;
}

int NormalAccount::getBalance() const {
	return Account::getBalance();
}

void NormalAccount::inMoney(int in_money) {
	Account::inMoney(in_money + (int)(Account::getBalance() * interest / 100));
}

NormalAccount::~NormalAccount() { }