#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "cpp_proj_Account.h"

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

#endif // !__MANAGER_H__
