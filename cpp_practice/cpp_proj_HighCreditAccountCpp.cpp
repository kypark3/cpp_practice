#include "cpp_proj_BankingCommonDecl.h"
#include "cpp_proj_HighCreditAccount.h"


HighCreditAccount::HighCreditAccount(const char name[], int balance, int ID, int interest, int creditGrade)
	: NormalAccount(name, balance, ID, interest), creditGrade(creditGrade) { }

void HighCreditAccount::showAccountInfo() const {
	NormalAccount::showAccountInfo();
	cout << "신용등급 : ";
	CREDIT_GRADE::ShowCreditGrade(creditGrade);
}

int HighCreditAccount::getBalance() const {
	return Account::getBalance();
}

void HighCreditAccount::inMoney(int in_money) {
	NormalAccount::inMoney(in_money + (int)(Account::getBalance() * creditGrade / 100));
}

HighCreditAccount::~HighCreditAccount() { }


