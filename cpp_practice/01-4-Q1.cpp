#include <iostream>
#define FUNC(x,y) (x*y)


inline int FUNC1(int a, int b) {
	return a * b;
}


int main() {

	std::cout << FUNC1(4, 3) << std::endl; 
	// �ζ��� �Լ� -> ��ũ���� ���������� ��ǥ���� ����ӵ��� ������ �Լ��� ������ ��, ������� ����
	std::cout << FUNC(4, 3) << std::endl; 
	// ��ũ��

	return 0;

}