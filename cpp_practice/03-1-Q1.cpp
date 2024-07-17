#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

struct Point {

	int x_pos;
	int y_pos;

	void MovePos(int x, int y) {
		x_pos += x;
		y_pos += y;
	}

	void AddPoint(const Point &pos) {
		x_pos += pos.x_pos;
		y_pos += pos.y_pos;
	}

	void ShowPosition() {
		cout << "[" << x_pos << ", " << y_pos << "]" << endl;
	}
};

int main() {

	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}
