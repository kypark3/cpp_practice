#include <iostream>

int SimpleFunc(int a = 10) {

	return a + 1;
}

int SimpleFunc(void) {
	return 10;
}

/* ��������?
�����ε� �Ұ� 
�����Լ����� SimpleFunc() �ϸ� ��� ���� ��
*/

int main() {

	//SimpleFunc();

	return 0;
}

