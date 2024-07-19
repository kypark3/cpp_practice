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

	Account *accounts[100]; // 최대 계좌의 갯수는 100개
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
			cout << "[입    금]" << endl;
			cout << "입금할 계좌 ID를 입력하세요 :"; cin >> input_ID;
			cout << "입금 금액을 입력하세요 :"; cin >> input_money;
			deposit(accounts, &account_num, input_ID, input_money);
			break;
		case OPER::WITHDRAW:
			int output_ID, output_money;
			cout << "[출    금]" << endl;
			cout << "출금할 계좌 ID를 입력하세요 :"; cin >> output_ID;
			cout << "출금 금액을 입력하세요 :"; cin >> output_money;
			withdraw(accounts, &account_num, output_ID, output_money);
			break;
		case OPER::INQUIRE:
			showAllAccount(accounts, &account_num);
			break;
		case OPER::EXIT:
			cout << endl << "----프로그램 종료----" << endl << endl;
			deleteAccount(accounts, &account_num);
			return 0;
		default:
			cout << endl << "----잘못된 Menu를 입력하였습니다. 다시 입력해주세요----" << endl << endl;
		}
	}
	

	return 0;
}

void showMenu() {
	cout << "----Menu----" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입     금" << endl;
	cout << "3. 출     금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void deleteAccount(Account **accounts, int *account_num) {
	for (int i = 0; i < *account_num; i++) {
		delete accounts[i];
	}
}


void withdraw(Account **accounts, int *account_num, int ID, int output_money) {

	if (output_money < 0)
	{
		cout << endl << "----잘못된 입금 금액을 입력하였습니다. (1이상 자연수 입력)----" << endl << endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < *account_num; i++) {
		if (accounts[i]->getAccountID() == ID) {
			isfoundAccount = true;
			if (accounts[i]->getBalance() >= output_money) {
				accounts[i]->outMoney(output_money);
				cout << endl << "계좌 잔액 : " << accounts[i]->getBalance() << endl;
				cout << "-----------" << endl <<endl;
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


void deposit(Account **accounts, int *account_num, int ID , int input_money) {
	
	if (input_money < 0)
	{
		cout <<endl << "----잘못된 입금 금액을 입력하였습니다. (1이상 자연수 입력)----" << endl <<endl;
		return;
	}
	bool isfoundAccount = false;

	for (int i = 0; i < *account_num; i++) {
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

void showAllAccount(Account **accounts, int *account_num) {
	for (int i = 0; i < *account_num; i++) {
		accounts[i]->showAccountInfo();
	}
}

void makeAccount(Account **account , int *account_num) {
	
	char name[10];
	int ID = -1;
	int balance = -1;
	cout << "[계좌 개설]" << endl;
	cout << "계 좌 ID :"; cin >> ID;
	cout << "이    름 :"; cin >> name;
	cout << "최초 입금액 :"; cin >> balance; cout << endl;

	if (ID < 0 ) { // 문자가 입력됬을때 예외를 어떻게처리할까? 
		cout << "잘못된 ID 입니다. (0 이상 자연수 입력)" << endl; 
		return;
	}
	else if (balance < 0) { // 문자가 입력됬을때 예외를 어떻게처리할까?
		cout << "잘못된 입금액을 입력하였습니다. (0이상 자연수 입력)" << endl; 
		return;
	}
	//동일한 계좌가 있을때 예외처리는??

	account[*account_num] = new Account(name,balance,ID,*account_num);
	(*account_num)++;

}

