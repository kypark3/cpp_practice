#include "cpp_proj_BankingCommonDecl.h"

void CREDIT_GRADE::ShowCreditGrade(int oper){
	switch (oper)
	{
	case CREDIT_GRADE::ONETOA:
		cout << "A(7%)" << endl;
		break;
	case CREDIT_GRADE::TWOTOB:
		cout << "B(4%)" << endl;
		break;
	case CREDIT_GRADE::THREETOC:
		cout << "C(2%)" << endl;
		break;
	}
}