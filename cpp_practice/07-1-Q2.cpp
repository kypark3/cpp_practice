#include <iostream>
#include <cstring>
#pragma warning (disable :4996)
using std::cout;
using std::endl;
using std::cin;

class MyFriendInfo {
private:
	char *name;
	const int age;
public:

	MyFriendInfo(const char _name[], int _age) : age(_age) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		cout << "MyFriendInfo create" << endl;
	}

	~MyFriendInfo() {
		delete []name;
		cout << "MyFriendInfo delete" << endl;
	}

	void ShowMyFriendInfo() const {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
};


class MyFriendDetailInfo : public MyFriendInfo {
private:
	char *addr;
	char *phone;
public:
	MyFriendDetailInfo(const char _name[], int _age, const char _addr[], const char _phone[]) : MyFriendInfo(_name, _age) {

		addr = new char[strlen(_addr) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(addr, _addr);
		strcpy(phone, _phone);
		cout << "MyFriendDetailInfo create" << endl;

	}

	~MyFriendDetailInfo() {
		delete []addr;
		delete[]phone;
		cout << "MyFriendDetailInfo delete" << endl;
	}

	void ShowMyFriendDetailInfo() const {
		ShowMyFriendInfo();
		cout << "주소 : " << addr << endl;
		cout << "전화번호 : " << phone << endl;
	}
};


int main() {

	MyFriendDetailInfo F1("낙타", 29, "경기도 안양시 동안구", "010-5678-1212");
	MyFriendDetailInfo F2("곱등이", 28, "경기도 안양시 띠로링", "010-1234-1313");
	F1.ShowMyFriendDetailInfo();
	F2.ShowMyFriendDetailInfo();

	return 0;
}

