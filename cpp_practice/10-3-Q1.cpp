#include <iostream>


using std::cin;
using std::cout;

class Point {
	int xpos;
	int ypos;

public:
	Point(int x =0, int y = 0) : xpos(x), ypos(y) { }

	void Show() const{
		cout << xpos << "," << ypos<< std::endl;
	}
	friend std::istream &operator>>(std::istream& is,Point &point);
	friend std::ostream &operator<<(std::ostream &os, Point &point);

};

std::istream &operator>>(std::istream& is,Point &point) {
	int x, y;
	cin >> x >> y;
	point.xpos = x;
	point.ypos = y;

	return is;
}

std::ostream &operator<<(std::ostream &os, Point &point) {
	cout << point.xpos << "," << point.ypos << std::endl;
	return os;
}

int main() {

	cout << " 입력 x,y : ";
	Point pos1, pos3, pos4;
	std::cin >> pos1 >> pos3 >> pos4;
	std::cout << pos1 << pos3 << pos4;

	cout << " 입력 x,y : ";
	Point pos2;
	std::cin >> pos2;
	std::cout << pos2;
	return 0;
}