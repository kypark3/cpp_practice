#include <iostream>

using namespace std;


class Point {
	int xpos;
	int ypos;

public:
	Point(int x, int y) :xpos(x) ,ypos(y) { }

	Point& operator-= (Point &p1);
	Point& operator+= (Point &p1);
	
	void Showinfo();

};

void Point::Showinfo() {
	cout << xpos << "," << ypos << endl;
}

Point& Point::operator-=(Point &p1 ) {
	xpos -= p1.xpos;
	ypos -= p1.ypos;
	return *this;
}

Point& Point::operator+=(Point &p1) {
	xpos += p1.xpos;
	ypos += p1.ypos;
	return *this;
}

int main() {

	Point p1(10, 20);
	Point p2(1, 3);

	(p1 += p2).Showinfo();
	



	return 0;
}