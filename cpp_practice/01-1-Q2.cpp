#include <iostream>

int main() {

	char name[100];
	char Pn[100];

	std::cout << "�̸� �Է� : ";
	std::cin >> name;
	std::cout << std::endl;

	std::cout << "��ȭ��ȣ �Է�(-����) : ";
	std::cin >> Pn;
	std::cout << std::endl;

	std::cout << "�̸� : " << name << " " << "��ȭ��ȣ : " << Pn << std::endl;


	return 0;
}