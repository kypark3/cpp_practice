#ifndef __POINTER_H__
#define __POINTER_H__
#include <iostream>
#include <cstdlib>
#pragma warning (disable : 4996)
using std::cin;
using std::cout;
using std::endl;

namespace POINTER{
	enum 
	{
		CHAR_LEN = 50
	};
}

class Pointer{
private:
	char s[POINTER::CHAR_LEN];
public:
	void saveS(const char *newS);
	void printS();

};


#endif