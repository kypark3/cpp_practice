#include "cpp_proj.h"

int main() {

	Manager manager;
	int oper;
	while (1) {
		manager.showMenu();
		cout << "���� : ";
		cin >> oper;
		cout << endl;
		switch (oper) {
		case OPER::MAKE:
			manager.makeAccount();
			cout << endl;
			break;
		case OPER::DEPOSIT:
			int input_ID, input_money;
			cout << "[��    ��]" << endl;
			cout << "�Ա��� ���� ID�� �Է��ϼ��� :"; cin >> input_ID;
			cout << "�Ա� �ݾ��� �Է��ϼ��� :"; cin >> input_money;
			manager.deposit(input_ID, input_money);
			cout << endl;
			break;
		case OPER::WITHDRAW:
			int output_ID, output_money;
			cout << "[��    ��]" << endl;
			cout << "����� ���� ID�� �Է��ϼ��� :"; cin >> output_ID;
			cout << "��� �ݾ��� �Է��ϼ��� :"; cin >> output_money;
			manager.withdraw(output_ID, output_money);
			cout << endl;
			break;
		case OPER::INQUIRE:
			manager.showAllAccount();
			cout << endl;
			break;
		case OPER::EXIT:
			cout << endl << "----���α׷� ����----" << endl << endl;
			return 0;
		default:
			cout << endl << "----�߸��� Menu�� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���----" << endl << endl;
		}
	}

	return 0;
}


