#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

class AAA {
	char *ch;
	int a;
public:
	explicit AAA(const char ch[], int a) : a(a) {
		int len = strlen(ch) + 1;
		this->ch = new char[len];
		strcpy(this->ch, ch);
		cout << "create" << endl;
	}
	
	explicit AAA(const AAA &copy) : a(copy.a){
		int len = strlen(copy.ch) + 1;
		ch = new char[len];
		strcpy(ch, copy.ch);
	}
	
	~AAA() {
		delete []ch;
		cout << "delete" << endl;
	}

	int return_value() const {
		return a;
	}
};


int main() {

	AAA a("what are you doing now", 3);
	AAA b(a);
	cout << b.return_value() << endl;

	return 0;
}