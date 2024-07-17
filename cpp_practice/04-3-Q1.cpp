#include <iostream>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	
	Point(int x_pos, int y_pos) :x(x_pos) , y(y_pos) { }

	void ShowPointInfo () const
	{
		cout << "[" << x << "," << y << "]" << endl;
	}

};

class Circle {
	Point p;
	int rad;
public:
	Circle(int x_pos, int y_pos, int r) :p(x_pos, y_pos){
		rad = r;
		cout << "create Circle object" << endl;
	}

	void ShowCircleInfo() const {
		p.ShowPointInfo();
		cout << "Radius :" << rad << endl;
	}
};

class Ring {
	Circle innerCir;
	Circle outerCir;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) : innerCir(x1, y1, r1), outerCir(x2, y2, r2) {
		cout << "create Ring object" << endl;
	}

	void ShowRingInfo() {
		cout << "inner Circle info..." << endl;
		innerCir.ShowCircleInfo();

		cout << "inner Circle info..." << endl;
		outerCir.ShowCircleInfo();
	}
};

int main() {

	Ring r(1, 1, 2, 2, 2, 9);
	r.ShowRingInfo();

	return 0;
}