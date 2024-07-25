#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int _width, int _height) :width(_width), height(_height) { }
	void ShowAreaInfo ()const;
};

void Rectangle::ShowAreaInfo() const{
	cout << "³ÐÀÌ : "<< width * height << endl;
	return ;
}


class Square : public Rectangle {
public:
	Square(int length) : Rectangle(length, length){ }

};

int main() {

	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}
