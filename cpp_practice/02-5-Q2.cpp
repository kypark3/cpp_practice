#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
/*
�� �Լ��� �̿��ؼ� 0�̻� 100���� ������ �� 5�� �����ϴ� ����
*/

int main() {

	srand(time(NULL)); // �õ� ���� ���� �ð����� ����
	for (int i = 1; i <= 5; i++) {
		cout << "Random n " << i << " is : " <<  (rand()% 101) << endl;
	}

	return 0;
}

/*text ����*/