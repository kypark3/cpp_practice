#include <iostream>
#define FUNC(x,y) (x*y)


inline int FUNC1(int a, int b) {
	return a * b;
}


int main() {

	std::cout << FUNC1(4, 3) << std::endl; 
	// 인라인 함수 -> 매크로의 여러장점중 대표적인 실행속도에 이점을 함수로 가져옴 즉, 성능향상에 도움
	std::cout << FUNC(4, 3) << std::endl; 
	// 매크로

	return 0;

}