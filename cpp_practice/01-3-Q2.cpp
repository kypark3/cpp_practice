#include <iostream>

int SimpleFunc(int a = 10) {

	return a + 1;
}

int SimpleFunc(void) {
	return 10;
}

/* 문제점은?
오버로딩 불가 
메인함수에서 SimpleFunc() 하면 어떤걸 할지 모름
*/

int main() {

	//SimpleFunc();

	return 0;
}

