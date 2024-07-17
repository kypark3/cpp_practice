#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct __Point {

	int x_pos;
	int y_pos;

}Point;

Point &PntAdder(const Point &p1, const Point &p2);

int main() {

	Point *p1 = new Point;
	Point *p2 = new Point;

	p1->x_pos = 1;
	p1->y_pos = 2;
	p2->x_pos = 3;
	p2->y_pos = 4;

	Point &resP = PntAdder(*p1, *p2);
	cout << resP.x_pos << ", "<< resP.y_pos << endl;

	delete p1;
	delete p2;
	delete &resP;
	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2) {

	Point *tmp = new Point;
	tmp->x_pos = p1.x_pos + p2.x_pos;
	tmp->y_pos = p1.y_pos + p2.y_pos;

	return *tmp;
}