#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

int main() {

	int *n = new int;

	printf("%p\n", n);
	printf("%o\n", &n);
	printf("%p\n", n);


	return 0;
}