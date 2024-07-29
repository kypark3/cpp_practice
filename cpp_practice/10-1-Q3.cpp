#include <iostream>

using namespace std;

class Point {
	int xpos;
	int ypos;

public:
	Point(int x, int y) :xpos(x), ypos(y) { }
	friend bool operator==(Point &p1, Point &p2);
	friend bool operator!=(Point &p1, Point &p2);

};

bool operator==(Point &p1, Point &p2) {
	return p1.xpos == p2.xpos && p1.ypos == p2.ypos;
}

bool operator!=(Point &p1, Point &p2) { // 연산자 오버로딩을 활용함
	return !(p1 == p2);
}

int main() {
	Point p1(1, 2);
	Point p2(2, 1);
	if (p1 == p2) cout << "all member is equal" << endl; // 모든 멤버변수가 같으면 true
	else cout << "all member isn't equal" << endl;

	if (p1 != p2) cout << "all member isn't equal" << endl; // 모든 멤버변수가 다르면 ture
	else cout << "all member is equal" << endl;;

	return 0;
}