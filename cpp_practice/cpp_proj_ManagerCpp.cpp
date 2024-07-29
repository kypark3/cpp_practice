
#include "cpp_proj_BankingCommonDecl.h"
#include "cpp_proj_Manager.h"
#include "cpp_proj_Account.h"
#include "cpp_proj_NormalAccount.h"
#include "cpp_proj_HighCreditAccount.h"

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

