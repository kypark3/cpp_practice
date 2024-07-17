#include <iostream>

//using namespace std; <- �̰ͺ��ٴ�

using std::cout;
using std::cin;
using std::endl;
// �̰��� ������� ������ �����Ұ� �ֳ��� �̸� �浹�� �߻��� ���ɼ��� ��������� �������� �����̴�.


namespace A {
	namespace B{
		namespace C {
			int a = 1;
			int b = 2;
		}
	}
}

namespace ABC = A::B::C; // �̸������� �ߺ��� ��Ī���� ����

namespace Hybrid 
{
	void Hybridfunc() {
		std::cout << "So simple func!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}

}


//��������
int val = 10;

int main() {

	using Hybrid::Hybridfunc;
	Hybridfunc();

	int n;
	cout << "it's possible!" << endl;
	cin >> n;
	cout << n;
	cout << endl;
	cout << ABC::a << endl;
	cout << ABC::b << endl;

	int val = 20;
	val += 10; // �������� 30
	cout << val << endl;

	cout << ::val << endl; //�������� 10

	return 0;
}