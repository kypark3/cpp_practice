#include <iostream>

int main()
{
	int a;
	int sum = 0;
	for (int i = 0; i < 5; i++) {

		std::cout << i+1 <<"��° ���� �Է� : ";
		std::cin >> a;
		sum += a;
	}

	std::cout << "�հ�: " << sum;

	return 0;
}