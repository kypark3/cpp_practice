#include <iostream>

using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y){ }
	void Showinfo() const{
		cout << xpos << "," << ypos << endl;
	}

	Point operator-();
	friend Point operator~(const Point &p);
	
	//후위 증가
	const Point operator++(int) { // int형의 작성은 전위와 차이를 주기위함
		const Point tempObj(xpos, ypos); // 임시로 저장하고 있는 obj
		xpos++;
		ypos++;
		return tempObj;
	}

};

Point Point::operator-() {
	Point pos(-xpos, -ypos);
	return pos;
}

Point operator~(const Point &p) {
	Point pos(p.ypos, p.xpos);
	return pos;
}
int main() {

	Point p1(9, 7);
	p1.Showinfo(); //  9,-7
	Point p2 = -p1;
	p2.Showinfo(); // -9 ,7

	(~p2).Showinfo(); // 7 -9
	p2.Showinfo(); // 9, -7
	

	Point ptest(10, 20);
	Point ptest1 = ptest++;

	ptest1.Showinfo();
	ptest.Showinfo();


	return 0;
}