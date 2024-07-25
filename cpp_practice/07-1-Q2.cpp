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
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
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
		cout << "�ּ� : " << addr << endl;
		cout << "��ȭ��ȣ : " << phone << endl;
	}
};


int main() {

	MyFriendDetailInfo F1("��Ÿ", 29, "��⵵ �Ⱦ�� ���ȱ�", "010-5678-1212");
	MyFriendDetailInfo F2("������", 28, "��⵵ �Ⱦ�� ��θ�", "010-1234-1313");
	F1.ShowMyFriendDetailInfo();
	F2.ShowMyFriendDetailInfo();

	return 0;
}

