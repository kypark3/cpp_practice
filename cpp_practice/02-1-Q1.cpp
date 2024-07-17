#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void func1(int& n);
void func2(int& n);

int main() {

	int n1, n2;
	cin >> n1 >> n2;
	func1(n1);
	func2(n2);

	cout << "n + 1 : " << n1 << endl;
	cout << "n(-) : " << n2 << endl;

	return 0;
}
<<<<<<< HEAD

void func1(int &n) {
	n += 1;
}

void func2(int& n) {
	n *= -1;
}
=======
/*
test
*/
>>>>>>> d63dabc5efeb4ed0063e37b66fa7849195f3a67b
