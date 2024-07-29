#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	char *name; // ÀÌ¸§
	int balance; // ÀÜ¾×
	const int ID; // °í°´ ID

public:
	Account(const char name[], int balance, int ID);
	Account(const Account &account);
	virtual void showAccountInfo() const;
	int getAccountID() const;
	virtual int getBalance() const;
	virtual void inMoney(int in_money);
	void outMoney(int out_money);
	~Account();
};

#endif // __ACCOUNT_H__
