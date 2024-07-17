#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	const int n = 10;
	const int *ptr = &n;
	const int* (&rptr) = ptr;
	cout << *ptr << endl;
	cout << *rptr << endl;

	return 0;
}
