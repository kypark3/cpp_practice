#include <iostream>

int main() {

	int n;
	std::cout << "판매 금액을 만원단위로 입력(-1 to end): ";
	std::cin >> n;
	while (n != -1) {

		int res = 50 + (double)n * 12 / 100;
		std::cout << "이번달 급여: " << res << std::endl;
		std::cout << "판매 금액을 만원단위로 입력(-1 to end): ";

		std::cin >> n;
	}

	std::cout << "program shout down" << std::endl;

	return 0;
}