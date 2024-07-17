#include "03-2-Q2.h"

int main() {

	Pointer ptr;
	ptr.saveS("He is so kind!");
	ptr.printS();

	ptr.saveS("i love you");
	ptr.printS();

	return 0;
}

void Pointer::saveS(const char *newS) { // const ?

	strcpy(s, newS);
}
void Pointer::printS() {
	cout << s << endl;
}