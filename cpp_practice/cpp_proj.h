#ifndef __CPP_PROJ__
#define __CPP_PROJ__
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

namespace OPER {
	enum {
		MAKE = 1, DEPOSIT = 2, WITHDRAW = 3, INQUIRE = 4, EXIT = 5
	};
}

namespace CREDIT_GRADE {
	enum {
		ONETOA = 7 , TWOTOB = 4 , THREETOC= 2
	};
	void ShowCreditGrade(int oper) {
		switch (oper)
		{
		case CREDIT_GRADE::ONETOA:
			cout << "A(7%)" << endl;
			break;
		case CREDIT_GRADE::TWOTOB:
			cout << "B(4%)" << endl;
			break;
		case CREDIT_GRADE::THREETOC:
			cout << "C(2%)" << endl;
			break;
		}
	}
}

class Account {
private:
	char *name; // 이름
	int balance; // 잔액
	const int ID; // 고객 ID

public:
	Account(const char name[], int balance, int ID);
	Account(const Account &account);
	virtual void showAccountInfo() const;
	int getAccountID() const;
	virtual int getBalance() const;
	virtual void inMoney(int in_money);
	void outMoney(int out_money);
	~Account();
};

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
	cout << "이   름 : " << name << endl;
	cout << "잔   액 : " << balance << endl;
	cout << "계좌 ID : " << ID << endl;
}

Account::~Account() {
	cout << "delete account name" << endl;
	delete[]name;
}

class NormalAccount :public Account {
private:
	int interest;
public:
	NormalAccount(const char name[], int balance, int ID, int interest);
	virtual void showAccountInfo() const;
	virtual int getBalance() const;
	virtual void inMoney(int in_money);
	~NormalAccount() { }
};

NormalAccount::NormalAccount(const char name[], int balance, int ID, int interest)
	: Account(name, balance, ID), interest(interest) { }

void NormalAccount::showAccountInfo() const {
	Account::showAccountInfo();
	cout << "이자율 : " << interest << endl;
}

int NormalAccount::getBalance() const {
	return Account::getBalance();
}

void NormalAccount::inMoney(int in_money) {
	Account::inMoney(in_money + (int)(Account::getBalance() * interest / 100));
}

class HighCreditAccount : public NormalAccount {
private:
	int creditGrade;
public:
	HighCreditAccount(const char name[], int balance, int ID, int interest, int creditGrade);
	virtual void showAccountInfo() const;
	virtual int getBalance() const;
	virtual void inMoney(int in_money);
	~HighCreditAccount() { }
};

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


class Manager {
private:
	Account *accounts[100]; // 계좌의 갯수를 100개 이상 동적 할당하려면?
	int account_num;
public:
	Manager();
	void showMenu() const;
	void withdraw(int ID, int output_money);
	void deposit(int ID, int input_money);
	void showAllAccount() const;
	void makeAccount(); // 보통 예금 계좌, 신용 신뢰 계좌
	~Manager();
};

Manager::Manager() : account_num(0) { }

void Manager::showMenu() const {
	cout << "----Menu----" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입     금" << endl;
	cout << "3. 출     금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void Manager::withdraw(int ID, int output_money) {

	if (output_money < 0)
	{
		cout << endl << "----잘못된 출금 금액을 입력하였습니다. (1이상 자연수 입력)----" << endl << endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < account_num; i++) {
		if (accounts[i]->getAccountID() == ID) {
			isfoundAccount = true;
			if (accounts[i]->getBalance() >= output_money) {
				accounts[i]->outMoney(output_money);
				cout << endl << "계좌 잔액 : " << accounts[i]->getBalance() << endl;
				cout << "-----------" << endl << endl;
			}
			else
			{
				cout << endl << "계좌 잔액 : " << accounts[i]->getBalance() << endl;
				cout << "----잔액이 부족합니다.----" << endl << endl;
			}
		}
	}

	if (!isfoundAccount) {
		cout << endl << "---- 계좌를 찾지 못하였습니다. 계좌 ID를 다시 확인해 주세요. ----" << endl << endl;
		return;
	}

}

void Manager::deposit(int ID, int input_money) {

	if (input_money < 0)
	{
		cout << endl << "----잘못된 입금 금액을 입력하였습니다. (1이상 자연수 입력)----" << endl << endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < account_num; i++) {
		if (accounts[i]->getAccountID() == ID) {
			isfoundAccount = true;
			accounts[i]->inMoney(input_money);
			cout << "계좌 잔액 : " << accounts[i]->getBalance() << endl;
			cout << "-----------" << endl;
		}
	}

	if (!isfoundAccount) {
		cout << endl << "---- 계좌를 찾지 못하였습니다. 계좌 ID를 다시 확인해 주세요. ----" << endl << endl;
		return;
	}
}

void Manager::showAllAccount() const {
	for (int i = 0; i < account_num; i++) {
		cout << "----" << i + 1 << "번째 계좌 정보----" << endl;
		accounts[i]->showAccountInfo(); cout << endl;
	}
}

void Manager::makeAccount() {
	int choice;
	char name[10];
	int ID = -1;
	int balance = -1;
	int interest;
	int choice_creditGrade;

	cout << "[계좌 종류선택]" << endl;
	cout << "1. 보통 예금 계좌 / 2. 신용 신뢰 계좌" << endl;
	cout << "선택 : "; cin >> choice;
	if (choice == 1) {
		cout << "[보통예금계좌]" << endl;
		cout << "계 좌 ID :"; cin >> ID;
		cout << "이    름 :"; cin >> name;
		cout << "최초 입금액 :"; cin >> balance;
		cout << "이자율 : "; cin >> interest;

		if (ID < 0) { // 문자가 입력됬을때 예외를 어떻게처리할까? 
			cout << "잘못된 ID 입니다. (0 이상 자연수 입력)" << endl;
			return;
		}
		else if (balance < 0) { // 문자가 입력됬을때 예외를 어떻게처리할까?
			cout << "잘못된 입금액을 입력하였습니다. (0이상 자연수 입력)" << endl;
			return;
		}
		//동일한 계좌가 있을때 예외처리는??

		accounts[account_num++] = new NormalAccount(name, balance, ID, interest);
	}
	else if (choice == 2) {
		cout << "[신용신뢰계좌]" << endl;
		cout << "계 좌 ID :"; cin >> ID;
		cout << "이    름 :"; cin >> name;
		cout << "최초 입금액 :"; cin >> balance;
		cout << "이자율 : "; cin >> interest;
		cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> choice_creditGrade;

		if (ID < 0) { // 문자가 입력됬을때 예외를 어떻게처리할까? 
			cout << "잘못된 ID 입니다. (0 이상 자연수 입력)" << endl;
			return;
		}
		else if (balance < 0) { // 문자가 입력됬을때 예외를 어떻게처리할까?
			cout << "잘못된 입금액을 입력하였습니다. (0이상 자연수 입력)" << endl;
			return;
		}
		//동일한 계좌가 있을때 예외처리는??
		if (choice_creditGrade == 1) {
			accounts[account_num++] = new HighCreditAccount(name, balance, ID, interest, CREDIT_GRADE::ONETOA);
		}
		else if (choice_creditGrade == 2) {
			accounts[account_num++] = new HighCreditAccount(name, balance, ID, interest, CREDIT_GRADE::TWOTOB);
		}
		else if (choice_creditGrade == 3) {
			accounts[account_num++] = new HighCreditAccount(name, balance, ID, interest, CREDIT_GRADE::THREETOC);
		}

	}
	else {
		cout << "잘못된 입력입니다. 1또는 2를 선택해주세요." << endl;
		return;
	}
}

Manager::~Manager() {
	for (int i = 0; i < account_num; i++) {
		delete accounts[i];
	}
}

#endif