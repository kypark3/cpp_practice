#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "cpp_proj_Account.h"

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
	void makeAccount(); // 보통 예금 계좌, 신용 신뢰 계좌
	~Manager();
};

#endif // !__MANAGER_H__
