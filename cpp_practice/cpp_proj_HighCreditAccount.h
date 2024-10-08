#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "cpp_proj_NormalAccount.h"
#include "cpp_String.h"
class HighCreditAccount : public NormalAccount {
private:
	int creditGrade;
public:
	HighCreditAccount(String name, int balance, int ID, int interest, int creditGrade);
	virtual void showAccountInfo() const;
	virtual int getBalance() const;
	virtual void inMoney(int in_money);
	~HighCreditAccount();
};

#endif // !__HIGHCREDITACCOUNT_H__

