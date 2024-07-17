#include <iostream>

//using namespace std; <- 이것보다는

using std::cout;
using std::cin;
using std::endl;
// 이것을 사용하자 일일히 지정할것 왜나면 이름 충돌이 발생할 가능성이 상대적으로 높아지기 떄문이다.


namespace A {
	namespace B{
		namespace C {
			int a = 1;
			int b = 2;
		}
	}
}

namespace ABC = A::B::C; // 이름공간의 중복을 별칭으로 참조

namespace Hybrid 
{
	void Hybridfunc() {
		std::cout << "So simple func!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}

}


//전역변수
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
	val += 10; // 지역변수 30
	cout << val << endl;

	cout << ::val << endl; //전역변수 10

	return 0;
}