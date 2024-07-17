#include <iostream>

using std::cin;
using std::cout;
using std::endl;
void SwapByRef2(int& ref1, int& ref2);


int main() {

	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	// SwapByRef2(22, 33); // error : 참조변수는 상수를 매개변수로 받을수 없다.

	cout << "val1 :" << val1<< endl;
	cout << "val2 :" << val2 << endl;


	return 0;
}

void SwapByRef2(int& ref1, int& ref2) {
	int tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

