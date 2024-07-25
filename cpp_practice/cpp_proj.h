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
	char *name; // �̸�
	int balance; // �ܾ�
	const int ID; // �� ID

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
	Account *accounts[100]; // ������ ������ 100�� �̻� ���� �Ҵ��Ϸ���?
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
	cout << "1. ���� ����" << endl;
	cout << "2. ��     ��" << endl;
	cout << "3. ��     ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void Manager::withdraw(int ID, int output_money) {

	if (output_money < 0)
	{
		cout << endl << "----�߸��� �Ա� �ݾ��� �Է��Ͽ����ϴ�. (1�̻� �ڿ��� �Է�)----" << endl << endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < account_num; i++) {
		if (accounts[i]->getAccountID() == ID) {
			isfoundAccount = true;
			if (accounts[i]->getBalance() >= output_money) {
				accounts[i]->outMoney(output_money);
				cout << endl << "���� �ܾ� : " << accounts[i]->getBalance() << endl;
				cout << "-----------" << endl << endl;
			}
			else
			{
				cout << endl << "���� �ܾ� : " << accounts[i]->getBalance() << endl;
				cout << "----�ܾ��� �����մϴ�.----" << endl << endl;
			}
		}
	}

	if (!isfoundAccount) {
		cout << endl << "---- ���¸� ã�� ���Ͽ����ϴ�. ���� ID�� �ٽ� Ȯ���� �ּ���. ----" << endl << endl;
		return;
	}

}

void Manager::deposit(int ID, int input_money) {

	if (input_money < 0)
	{
		cout << endl << "----�߸��� �Ա� �ݾ��� �Է��Ͽ����ϴ�. (1�̻� �ڿ��� �Է�)----" << endl << endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < account_num; i++) {
		if (accounts[i]->getAccountID() == ID) {
			isfoundAccount = true;
			accounts[i]->inMoney(input_money);
			cout << "���� �ܾ� : " << accounts[i]->getBalance() << endl;
			cout << "-----------" << endl;
		}
	}

	if (!isfoundAccount) {
		cout << endl << "---- ���¸� ã�� ���Ͽ����ϴ�. ���� ID�� �ٽ� Ȯ���� �ּ���. ----" << endl << endl;
		return;
	}
}

void Manager::showAllAccount() const {
	for (int i = 0; i < account_num; i++) {
		cout << "----" << i + 1 << "��° ���� ����----" << endl;
		accounts[i]->showAccountInfo(); cout << endl;
	}
}

void Manager::makeAccount() {

	char name[10];
	int ID = -1;
	int balance = -1;
	cout << "[���� ����]" << endl;
	cout << "�� �� ID :"; cin >> ID;
	cout << "��    �� :"; cin >> name;
	cout << "���� �Աݾ� :"; cin >> balance;

	if (ID < 0) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�? 
		cout << "�߸��� ID �Դϴ�. (0 �̻� �ڿ��� �Է�)" << endl;
		return;
	}
	else if (balance < 0) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�?
		cout << "�߸��� �Աݾ��� �Է��Ͽ����ϴ�. (0�̻� �ڿ��� �Է�)" << endl;
		return;
	}
	//������ ���°� ������ ����ó����??

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
	cout << "��   �� : " << name << endl;
	cout << "��   �� : "<< balance << endl;
	cout << "���� ID : " << ID << endl;
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

