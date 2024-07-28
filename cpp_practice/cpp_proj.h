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
	char *name; // �̸�
	int balance; // �ܾ�
	const int ID; // �� ID

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
	cout << "��   �� : " << name << endl;
	cout << "��   �� : " << balance << endl;
	cout << "���� ID : " << ID << endl;
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
	cout << "������ : " << interest << endl;
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
	cout << "�ſ��� : ";
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
	Account *accounts[100]; // ������ ������ 100�� �̻� ���� �Ҵ��Ϸ���?
	int account_num;
public:
	Manager();
	void showMenu() const;
	void withdraw(int ID, int output_money);
	void deposit(int ID, int input_money);
	void showAllAccount() const;
	void makeAccount(); // ���� ���� ����, �ſ� �ŷ� ����
	~Manager();
};

Manager::Manager() : account_num(0) { }

void Manager::showMenu() const {
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
		cout << endl << "----�߸��� ��� �ݾ��� �Է��Ͽ����ϴ�. (1�̻� �ڿ��� �Է�)----" << endl << endl;
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
	int choice;
	char name[10];
	int ID = -1;
	int balance = -1;
	int interest;
	int choice_creditGrade;

	cout << "[���� ��������]" << endl;
	cout << "1. ���� ���� ���� / 2. �ſ� �ŷ� ����" << endl;
	cout << "���� : "; cin >> choice;
	if (choice == 1) {
		cout << "[���뿹�ݰ���]" << endl;
		cout << "�� �� ID :"; cin >> ID;
		cout << "��    �� :"; cin >> name;
		cout << "���� �Աݾ� :"; cin >> balance;
		cout << "������ : "; cin >> interest;

		if (ID < 0) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�? 
			cout << "�߸��� ID �Դϴ�. (0 �̻� �ڿ��� �Է�)" << endl;
			return;
		}
		else if (balance < 0) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�?
			cout << "�߸��� �Աݾ��� �Է��Ͽ����ϴ�. (0�̻� �ڿ��� �Է�)" << endl;
			return;
		}
		//������ ���°� ������ ����ó����??

		accounts[account_num++] = new NormalAccount(name, balance, ID, interest);
	}
	else if (choice == 2) {
		cout << "[�ſ�ŷڰ���]" << endl;
		cout << "�� �� ID :"; cin >> ID;
		cout << "��    �� :"; cin >> name;
		cout << "���� �Աݾ� :"; cin >> balance;
		cout << "������ : "; cin >> interest;
		cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> choice_creditGrade;

		if (ID < 0) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�? 
			cout << "�߸��� ID �Դϴ�. (0 �̻� �ڿ��� �Է�)" << endl;
			return;
		}
		else if (balance < 0) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�?
			cout << "�߸��� �Աݾ��� �Է��Ͽ����ϴ�. (0�̻� �ڿ��� �Է�)" << endl;
			return;
		}
		//������ ���°� ������ ����ó����??
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
		cout << "�߸��� �Է��Դϴ�. 1�Ǵ� 2�� �������ּ���." << endl;
		return;
	}
}

Manager::~Manager() {
	for (int i = 0; i < account_num; i++) {
		delete accounts[i];
	}
}

#endif