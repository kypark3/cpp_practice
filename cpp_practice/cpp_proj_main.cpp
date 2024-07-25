#include "cpp_proj.h"

int main() {

	Manager manager;
	int oper;
	while (1) {
		manager.showMenu();
		cout << "선택 : ";
		cin >> oper;
		cout << endl;
		switch (oper) {
		case OPER::MAKE:
			manager.makeAccount();
			cout << endl;
			break;
		case OPER::DEPOSIT:
			int input_ID, input_money;
			cout << "[입    금]" << endl;
			cout << "입금할 계좌 ID를 입력하세요 :"; cin >> input_ID;
			cout << "입금 금액을 입력하세요 :"; cin >> input_money;
			manager.deposit(input_ID, input_money);
			cout << endl;
			break;
		case OPER::WITHDRAW:
			int output_ID, output_money;
			cout << "[출    금]" << endl;
			cout << "출금할 계좌 ID를 입력하세요 :"; cin >> output_ID;
			cout << "출금 금액을 입력하세요 :"; cin >> output_money;
			manager.withdraw(output_ID, output_money);
			cout << endl;
			break;
		case OPER::INQUIRE:
			manager.showAllAccount();
			cout << endl;
			break;
		case OPER::EXIT:
			cout << endl << "----프로그램 종료----" << endl << endl;
			return 0;
		default:
			cout << endl << "----잘못된 Menu를 입력하였습니다. 다시 입력해주세요----" << endl << endl;
		}
	}

	return 0;
}


