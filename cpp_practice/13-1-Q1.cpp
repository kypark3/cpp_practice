#include <iostream>

using std::cout;
using std::endl;

class Point {
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }

	void ShowPosition( ) const {
		cout << x << "," << y << endl;
	}
};

template <typename T>
void SwapData(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

int main( ) {
	Point p1(1, 2);
	Point p2(3, 4);
	SwapData(p1, p2);
	cout << "p1 : ";  p1.ShowPosition();
	cout << "p2 : "; p2.ShowPosition( );
	return 0;
}