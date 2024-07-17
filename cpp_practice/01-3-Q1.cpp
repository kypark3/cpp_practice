#include <iostream>
int boxVolume(int len) {
	return len * 1 * 1;
}


int boxVolume(int len, int wid) {
	return len * wid * 1;
}

int boxVolume(int len, int wid, int hei) {
	return len * wid * hei;
}

int main() {
	std::cout << "3,3,3 : " << boxVolume(3,3,3)<< std::endl;
	std::cout << "5,5,D : " << boxVolume(5,5) << std::endl;
	std::cout << "7,D,D : " << boxVolume(7) << std::endl;
	return 0;
}

