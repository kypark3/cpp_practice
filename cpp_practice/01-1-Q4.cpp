#include <iostream>

int main() {

	int n;
	std::cout << "�Ǹ� �ݾ��� ���������� �Է�(-1 to end): ";
	std::cin >> n;
	while (n != -1) {

		int res = 50 + (double)n * 12 / 100;
		std::cout << "�̹��� �޿�: " << res << std::endl;
		std::cout << "�Ǹ� �ݾ��� ���������� �Է�(-1 to end): ";

		std::cin >> n;
	}

	std::cout << "program shout down" << std::endl;

	return 0;
}