#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;


class note {
public:
	int n1;
	int n2;
	note(int n1 , int n2) : n1(n1), n2(n2) {

	}
};

int main() {
	note *a = new note(1,2);
	note &ptr1 = *a;

	cout << a << endl;
	cout << &ptr1 << endl;

	int num = 10;
	int *ptr = &num;

	printf("%p\n", &num);
	printf("%p\n", ptr);



	return 0;
}