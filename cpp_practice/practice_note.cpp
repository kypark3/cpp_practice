#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

class Point {
	int xpos;
	int ypos;

public:
	Point(int x, int y) : xpos(x), ypos(y){ }

	void ShowPosition() const {
		cout << xpos << "," << ypos << endl;
	}

	friend ostream& operator<< (ostream &, const Point &);
};

ostream &operator<< (ostream &os, const Point &point) {
	os << "[" << point.xpos << "," << point.ypos << "]" << endl;
	return os;
}

int main() {
	
	Point p1(1, 2);
	Point p2(2, 3);

	cout << p1 << p2 << endl;

	return 0;
}