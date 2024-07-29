
#include "cpp_proj_BankingCommonDecl.h"
#include "cpp_proj_Manager.h"
#include "cpp_proj_Account.h"
#include "cpp_proj_NormalAccount.h"
#include "cpp_proj_HighCreditAccount.h"

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

