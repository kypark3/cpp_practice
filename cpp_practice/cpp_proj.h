#ifndef __CPP_PROJ__
#define __CPP_PROJ__
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

namespace OPER {
	enum {
		MAKE = 1, DEPOSIT = 2, WITHDRAW = 3, INQUIRE = 4, EXIT = 5
	};
}

using namespace std;

class Account {
private:
	char *name; // 이름
	int balance; // 잔액
	const int ID; // 고객 ID

public:
	Account(const char name[], int balance, int ID);
	Account(const Account &account);
	void showAccountInfo() const;
	int getAccountID() const;
	int getBalance() const;
	void inMoney(int in_money);
	void outMoney(int out_money);
	~Account();

};


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
	void makeAccount();
	~Manager();

};

Manager::Manager() : account_num(0){ }

void Manager::showMenu() const{
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
		cout << endl << "----잘못된 입금 금액을 입력하였습니다. (1이상 자연수 입력)----" << endl << endl;
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

	char name[10];
	int ID = -1;
	int balance = -1;
	cout << "[계좌 개설]" << endl;
	cout << "계 좌 ID :"; cin >> ID;
	cout << "이    름 :"; cin >> name;
	cout << "최초 입금액 :"; cin >> balance;

	if (ID < 0) { // 문자가 입력됬을때 예외를 어떻게처리할까? 
		cout << "잘못된 ID 입니다. (0 이상 자연수 입력)" << endl;
		return;
	}
	else if (balance < 0) { // 문자가 입력됬을때 예외를 어떻게처리할까?
		cout << "잘못된 입금액을 입력하였습니다. (0이상 자연수 입력)" << endl;
		return;
	}
	//동일한 계좌가 있을때 예외처리는??

	accounts[account_num++] = new Account(name, balance, ID);
}

Manager::~Manager() {
	for (int i = 0; i < account_num; i++) {
		cout << "delete account" << endl;
		delete accounts[i];
	}
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

int Account::getAccountID() const{
	return ID;
}

void Account::showAccountInfo () const {
	cout << "이   름 : " << name << endl;
	cout << "잔   액 : "<< balance << endl;
	cout << "계좌 ID : " << ID << endl;
}

Account::Account(const char name[], int balance, int ID) : ID(ID), balance(balance){
	int name_len = strlen(name) + 1;
	this->name = new char[name_len];
	strcpy(this->name, name);
}

Account::Account(const Account &account) : balance(account.balance) , ID(account.ID){ 
	name = new char[strlen(account.name) + 1];
	strcpy(name, account.name);
}

Account::~Account() {
	cout << "delete account name" << endl;
	delete[]name;
}

#endif // __CPP_PROJ__

