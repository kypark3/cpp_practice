#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

namespace OPER {
	enum {
		MAKE = 1, DEPOSIT = 2, WITHDRAW = 3, INQUIRE = 4, EXIT = 5
	};
}

namespace CREDIT_GRADE {
	enum {
		ONETOA = 7, TWOTOB = 4, THREETOC = 2
	};

	void ShowCreditGrade(int oper);
}


#endif // !__BANKINGCOMMONDECL_H__
