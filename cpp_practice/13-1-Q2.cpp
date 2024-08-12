#include <iostream>

using std::endl;
using std::cout;

template <typename T>
T SumArray(T ar[], int len) {

	T sum = (T)0;
	for (int i = 0; i < len; i++) {
		sum += ar[i];
	}
	return sum;

}

int main( ) {

	int x[4] = { 1,2,3,4 };
	double y[3] = { 1.1 ,2.3,4.1 };

	cout << SumArray(x, 4) << endl;
	cout << SumArray(y, 3) << endl;

	return 0;
}