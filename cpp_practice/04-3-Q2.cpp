#include <iostream>
#include <cstdlib>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

namespace COMP_POS {
	enum 
	{
		CLERK = 1, SENIOR = 2, ASSIST = 3, MANAGER = 4
	};

	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK: 
			cout << "사원";
			break;
		case SENIOR:
			cout << "주임";
			break;
		case ASSIST:
			cout << "대리";
			break;
		case MANAGER:
			cout << "과장";
		}
	}
}

class NameCard {
private:
	char *name;
	char *companyName;
	char *phoneNum;
	int comp_Pos;
public:

	NameCard(const char input_name[], const char input_companyname[], const char input_phonenum[], int comp_pos) : comp_Pos(comp_pos) {
		name = new char[strlen(input_name) + 1];
		companyName = new char[strlen(input_companyname) + 1];
		phoneNum = new char[strlen(input_phonenum) + 1];
		strcpy(name, input_name);
		strcpy(companyName, input_companyname);
		strcpy(phoneNum, input_phonenum);
	}

	~NameCard() {
		delete []name;
		delete []companyName;
		delete []phoneNum;
	}

	void ShowNameCardInfo() const {
		cout << "이름 : " << name << endl;
		cout << "회사 이름 : " << companyName << endl;
		cout << "전화 번호 : " << phoneNum << endl;
		cout << "직급 : ";
		COMP_POS::ShowPositionInfo(comp_Pos); cout << endl;
	}
};

int main() {

	NameCard n1("park", "abc", "010-4646-7979", COMP_POS::ASSIST);
	NameCard n2("park1", "abc1", "010-4646-79179", COMP_POS::CLERK);

	n1.ShowNameCardInfo();
	n2.ShowNameCardInfo();


	return 0;
}