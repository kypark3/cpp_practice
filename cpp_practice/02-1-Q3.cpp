#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void SwapPointer1(int *(& ptr1), int *(& ptr2));
void SwapPointer2(int* (&pt1), int* (&pt2));

int main() {
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	SwapPointer1(ptr1, ptr2);
	cout << "num1 : " << *ptr1  << " adress ptr1:"<< ptr1 <<  " adress num1 :" << &num1 << endl;
	cout << "num2 : " << *ptr2 <<  " adress ptr2:"<< ptr2 << " adress num2 :" << &num2 << endl;

	SwapPointer2(ptr1, ptr2);
	cout << "num1 : " << *ptr1 << " adress ptr1:" << ptr1 << " adress num1 :" << &num1 << endl;
	cout << "num2 : " << *ptr2 << " adress ptr2:" << ptr2 << " adress num2 :" << &num2 << endl;


	return 0;
}

void SwapPointer1(int* (&pt1), int* (&pt2)) { // °ªÀ» ¹Ù²Þ

	int tmp = *pt1; 
	*pt1 = *pt2;
	*pt2 = tmp;
}

void SwapPointer2(int* (&pt1), int* (&pt2)) { // ÁÖ¼Ò¸¦ ¹Ù²Þ

	int *tmp = pt1;
	pt1 = pt2;
	pt2 = tmp;

}
