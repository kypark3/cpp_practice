#include <iostream>
#include <cstdlib>

// BoundCheckIntArray 활용

using std::ostream;
using std::endl;
using std::cout;
class Point {
	int xpos;
	int ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y) { }

	friend ostream& operator<<(ostream& os, const Point* p);
	friend ostream& operator<<(ostream& os, const Point& p);
};
//overload
ostream& operator<<(ostream& os, const Point& p) {
	os << p.xpos << "," << p.ypos << endl;
	return os;
}

ostream& operator<<(ostream& os, const Point* p) {
	os << p->xpos << "," << p->ypos << endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointArray {

	POINT_PTR *ar;
	int arlen;
public:
	BoundCheckPointArray(int len) : arlen(len) {
		ar = new POINT_PTR[len];
	}

	// 배열 연산자
	// ar.operator[] (5); // ar[5];
	POINT_PTR& operator[](int idx) {
		if (idx < 0 || idx >= arlen) {
			cout << " array idnex outof bound exception" << endl;
		}
		return ar[idx];
	}

	//overload
	POINT_PTR& operator[](int idx) const {
		if (idx < 0 || idx >= arlen) {
			cout << " array idnex outof bound exception" << endl;
		}
		return ar[idx];
	}

	int GetArLen( ) const { return arlen; }
	~BoundCheckPointArray( ) {
		delete[]ar;
	}
};

int main( ) {

	BoundCheckPointArray ar(3);
	ar[0] = new Point(1, 2);
	ar[1] = new Point(3, 4);
	ar[2] = new Point(5, 6);

	for (int i = 0; i < ar.GetArLen( ); i++) {
		cout << ar[i];
	}

	for (int i = 0; i < ar.GetArLen( ); i++) {
		cout << *(ar[i]);
	}
	delete ar[0];
	delete ar[1];
	delete ar[2];

	return 0;
}