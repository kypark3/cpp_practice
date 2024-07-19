#include "cpp_proj.h"

namespace OPER {
	enum {
		MAKE = 1, DEPOSIT = 2, WITHDRAW = 3, INQUIRE = 4, EXIT =5
	};
}

void makeAccount(Account **accounts, int *account_num);
void showAllAccount(Account **accounts, int *account_num);
void deposit(Account **accounts, int *account_num, int ID, int input_money);
void withdraw(Account **accounts, int *account_num, int ID, int output_money);
void deleteAccount(Account **accounts, int *account_num);
void showMenu();

int main() {

	Account *accounts[100]; // �ִ� ������ ������ 100��
	int account_num = 0;
	int oper;

	while (1) {
		showMenu();
		cin >> oper;
		switch (oper) {
		case OPER::MAKE:
			makeAccount(accounts, &account_num);
			break;
		case OPER::DEPOSIT:
			int input_ID, input_money;
			cout << "[��    ��]" << endl;
			cout << "�Ա��� ���� ID�� �Է��ϼ��� :"; cin >> input_ID;
			cout << "�Ա� �ݾ��� �Է��ϼ��� :"; cin >> input_money;
			deposit(accounts, &account_num, input_ID, input_money);
			break;
		case OPER::WITHDRAW:
			int output_ID, output_money;
			cout << "[��    ��]" << endl;
			cout << "����� ���� ID�� �Է��ϼ��� :"; cin >> output_ID;
			cout << "��� �ݾ��� �Է��ϼ��� :"; cin >> output_money;
			withdraw(accounts, &account_num, output_ID, output_money);
			break;
		case OPER::INQUIRE:
			showAllAccount(accounts, &account_num);
			break;
		case OPER::EXIT:
			cout << endl << "----���α׷� ����----" << endl << endl;
			deleteAccount(accounts, &account_num);
			return 0;
		default:
			cout << endl << "----�߸��� Menu�� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���----" << endl << endl;
		}
	}
	

	return 0;
}

void showMenu() {
	cout << "----Menu----" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ��     ��" << endl;
	cout << "3. ��     ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void deleteAccount(Account **accounts, int *account_num) {
	for (int i = 0; i < *account_num; i++) {
		delete accounts[i];
	}
}


void withdraw(Account **accounts, int *account_num, int ID, int output_money) {

	if (output_money < 0)
	{
		cout << endl << "----�߸��� �Ա� �ݾ��� �Է��Ͽ����ϴ�. (1�̻� �ڿ��� �Է�)----" << endl << endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < *account_num; i++) {
		if (accounts[i]->getAccountID() == ID) {
			isfoundAccount = true;
			if (accounts[i]->getBalance() >= output_money) {
				accounts[i]->outMoney(output_money);
				cout << endl << "���� �ܾ� : " << accounts[i]->getBalance() << endl;
				cout << "-----------" << endl <<endl;
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


void deposit(Account **accounts, int *account_num, int ID , int input_money) {
	
	if (input_money < 0)
	{
		cout <<endl << "----�߸��� �Ա� �ݾ��� �Է��Ͽ����ϴ�. (1�̻� �ڿ��� �Է�)----" << endl <<endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < *account_num; i++) {
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

void showAllAccount(Account **accounts, int *account_num) {
	for (int i = 0; i < *account_num; i++) {
		accounts[i]->showAccountInfo();
	}
}

void makeAccount(Account **account , int *account_num) {
	
	char name[10];
	int ID = -1;
	int balance = -1;
	cout << "[���� ����]" << endl;
	cout << "�� �� ID :"; cin >> ID;
	cout << "��    �� :"; cin >> name;
	cout << "���� �Աݾ� :"; cin >> balance; cout << endl;

	if (ID < 0 ) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�? 
		cout << "�߸��� ID �Դϴ�. (0 �̻� �ڿ��� �Է�)" << endl; 
		return;
	}
	else if (balance < 0) { // ���ڰ� �Է����� ���ܸ� ���ó���ұ�?
		cout << "�߸��� �Աݾ��� �Է��Ͽ����ϴ�. (0�̻� �ڿ��� �Է�)" << endl; 
		return;
	}
	//������ ���°� ������ ����ó����??

	account[*account_num] = new Account(name,balance,ID,*account_num);
	(*account_num)++;

}

