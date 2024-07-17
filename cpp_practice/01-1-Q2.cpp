#include <iostream>

int main() {

	char name[100];
	char Pn[100];

	std::cout << "이름 입력 : ";
	std::cin >> name;
	std::cout << std::endl;

	std::cout << "전화번호 입력(-포함) : ";
	std::cin >> Pn;
	std::cout << std::endl;

	std::cout << "이름 : " << name << " " << "전화번호 : " << Pn << std::endl;


	return 0;
}