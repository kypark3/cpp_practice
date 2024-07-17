#include <iostream>

using namespace std;

class Point {
private:
	int x_pos;
	int y_pos;
public:

	void InitPoint(int x, int y) {
		x_pos = x;
		y_pos = y;
	}

	void ShowPointInfo() const {
		cout << "[" << x_pos << "," << y_pos << "]" << endl;
	}
};


class Circle {
private:
	Point pos;
	int rad;
public:
	void initCircle(int x, int y, int r) {
		pos.InitPoint(x, y);
		rad = r;
	}
	void ShowCircleInfo() const {
		cout << "원의 중심 : ";
		pos.ShowPointInfo();
		cout << "반지름 : " << rad << endl <<endl;
	}
};

class Ring {
	Circle c1;
	Circle c2;
public:
	void initRing(int x1, int y1, int r1, int x2, int y2, int r2) {
		c1.initCircle(x1, y1, r1);
		c2.initCircle(x2, y2, r2);
	}

	void ShowRingInfo() const {
		cout << "inner Circle Info..." << endl;
		c1.ShowCircleInfo();

		cout << "Outter Circle Info..." << endl;
		c2.ShowCircleInfo();
	}
};

int main() {

	Ring ring;
	ring.initRing(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}



