#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

class Boy {
private:
	int a;
protected:
	int b;
public:
	int c;
};

class Girl : protected Boy{

public:
	void func() {
		//cout << a; 
		cout << b;
		cout << c;
	}

};

class G1 : private Girl {

public:
	void func1() {
		//cout << a;
		cout << b;
		cout << c;
	}
};


int main() {
	

	Girl g;
	G1 g1;
	Boy b;
	
	
	return 0;
}