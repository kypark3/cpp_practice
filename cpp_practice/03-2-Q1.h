#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Calculator {
private:
	double res;
	int Add_count;
	int Div_count;
	int Min_count;
	int Dup_count;
public:
	double Add(double x , double y);
	double Div(double x, double y);
	double Min(double x, double y);
	double Dup(double x, double y);
	void init();
	void ShowOpCount();
};

inline void Calculator::init() {
	Add_count = 0;
	Div_count = 0;
	Min_count = 0;
	Dup_count = 0;
	res = 0;
}
inline double Calculator::Add(double x, double y) {
	Add_count++;
	res = x + y;
	return res;
}

inline double Calculator::Div(double x, double y) {
	Div_count++;
	res = x / y;
	return res;
}

inline double Calculator::Min(double x, double y) {
	Min_count++;
	res = x - y;
	return res;
}

inline double Calculator::Dup(double x, double y) {
	Dup_count++;
	res = x * y;
	return res;
}

inline void Calculator::ShowOpCount() {
	cout << "µ¡¼À : " << Add_count << " ";
	cout << "–E¼À : " << Min_count << " ";
	cout << "°ö¼À : " << Dup_count << " ";
	cout << "³ª´°¼À : " << Div_count << " " << endl << endl;
}

#endif // !__CALCULATOR_H__
