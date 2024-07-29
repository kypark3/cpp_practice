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

bool operator!=(Point &p1, Point &p2) { // ������ �����ε��� Ȱ����
	return !(p1 == p2);
}

int main() {
	Point p1(1, 2);
	Point p2(2, 1);
	if (p1 == p2) cout << "all member is equal" << endl; // ��� ��������� ������ true
	else cout << "all member isn't equal" << endl;

	if (p1 != p2) cout << "all member isn't equal" << endl; // ��� ��������� �ٸ��� ture
	else cout << "all member is equal" << endl;;

	return 0;
}