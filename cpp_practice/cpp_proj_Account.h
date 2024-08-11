#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "cpp_String.h"

class Account {
private:
	String name;
	//char *name; // ÀÌ¸§
	int balance; // ÀÜ¾×
	const int ID; // °í°´ ID

public:
	Account(String name, int balance, int ID);
	Account(Account &account);
	virtual void showAccountInfo() const;
	int getAccountID() const;
	virtual int getBalance() const;
	virtual void inMoney(int in_money);
	void outMoney(int out_money);
	~Account();
};

#endif // __ACCOUNT_H__
