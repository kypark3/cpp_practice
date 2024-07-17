#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
/*
세 함수를 이용해서 0이상 100이하 난수를 총 5개 생성하는 예제
*/

int main() {

	srand(time(NULL)); // 시드 값을 현재 시간으로 설정
	for (int i = 1; i <= 5; i++) {
		cout << "Random n " << i << " is : " <<  (rand()% 101) << endl;
	}

	return 0;
}

/*text 수정*/