#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "cpp_proj_Account.h"

class NormalAccount :public Account {
private:
	int interest;
public:
	NormalAccount(const char name[], int balance, int ID, int interest);
	virtual void showAccountInfo() const;
	virtual int getBalance() const;
	virtual void inMoney(int in_money);
	~NormalAccount();
};


#endif // !__NORMALACCOUNT_H__
