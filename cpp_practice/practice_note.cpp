#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

class Boy {
private:
	static int n;
	int height;
	friend class Girl;
public:

	Boy(int _height) : height(_height) {

	}

	void showHeightinfo() const {
		cout << height;
	}

	static void func1() {
		func();
	}

	static void func() {

		func1();
		cout << "???";
	}

};

class Girl {


public:
	void showboyfreindinfo(Boy &boy) {
		boy.showHeightinfo();
	}

};


int main() {
	
	Boy::func();
	Boy b(1);

	return 0;
}