#include "03-2-Q1.h"

int main() {

	Calculator cal;
	cal.init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 + 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cout << "1.5 * 2.0 = " << cal.Dup(1.5, 2.0) << endl;
	cal.ShowOpCount();

	return 0;
}


