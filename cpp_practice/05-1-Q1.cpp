#include <iostream>
#include <cstdlib>
#pragma warning(disable:4996);
using std::cout;
using std::cin;
using std::endl;

namespace COMP_POS {

	enum {
		CLERK = 1, SENIOR = 2, ASSIST = 3, MANAGER = 4
	};

	void ShowCompPos(int oper)  {
		switch (oper) {
		case CLERK:
			cout << "clerk" << endl;
			break;
		case SENIOR:
			cout << "senior" << endl;
			break;
		case ASSIST:
			cout << "assist" << endl;
			break;
		case MANAGER:
			cout << "manager" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char *name;
	char *companyName;
	char *phonNum;
	int compPos;
public:

	explicit NameCard(const char _name[], const char _companyName[], const char _phoneNum[], int _compPos) : compPos(_compPos) {
		this->name = new char[strlen(_name) + 1]; // 변수이름이 같으면 충돌 가능성이있어서 this->name
		this->companyName = new char[strlen(_companyName) + 1];
		this->phonNum = new char[strlen(_phoneNum) + 1];
		strcpy(this->name, _name);
		strcpy(this->companyName, _companyName);
		strcpy(this->phonNum, _phoneNum);
		cout << "create" << endl;
	}

	explicit NameCard(const NameCard &copy) : compPos(copy.compPos) {
		name = new char[strlen(copy.name) + 1]; // 변수이름이 다르면 충돌가능성이 없으므로 name
		companyName = new char[strlen(copy.companyName) + 1];
		phonNum = new char[strlen(copy.phonNum) + 1];
		strcpy(this->name, copy.name);
		strcpy(this->companyName, copy.companyName);
		strcpy(this->phonNum, copy.phonNum);
		cout << "create copy" << endl;
	}

	~NameCard() {
		delete[]name;
		delete[]companyName;
		delete[]phonNum;
		cout << "delete" << endl;
	}

	void ShowNameCardInfo() const;
};

void NameCard::ShowNameCardInfo() const {
	cout << name << endl;
	cout << companyName << endl;
	cout << phonNum << endl;
	COMP_POS::ShowCompPos(compPos);
	cout << endl;
}


int main() {

	NameCard manClerk("pky", "pkpk", "010-1010-1010", COMP_POS::CLERK);
	NameCard copy1(manClerk);
	copy1.ShowNameCardInfo();

	return 0;
}

