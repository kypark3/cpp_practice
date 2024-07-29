#include <iostream>

using namespace std;

class Point {
	int xpos;
	int ypos;
public:
	Point(int x, int y) : xpos(x) ,ypos(y){ }

	void ShowInfo() const;
	
	// �ɹ��Լ���� ������ �����ε�
	Point operator-(Point &p);
	// �����Լ���� ������ �����ε�
	//friend Point operator-(Point &p1, Point &p2);
};

Point Point::operator-(Point &p) {
	Point newP(xpos - p.xpos, ypos - p.ypos);
	return newP;
}

void Point::ShowInfo() const {
	cout << xpos << "," << ypos << endl;
}
/*
Point operator-(Point &p1, Point &p2) {
	Point p3(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
	return p3;
}
*/
int main() {

	Point p1(10, 30);
	Point p2(20, 42);

	Point p3 = p2.operator-(p1);
	//Point p3 = p1 - p2;
	p3.ShowInfo();

	return 0;
}
