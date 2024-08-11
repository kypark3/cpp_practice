#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
#include "cpp_proj_BankingCommonDecl.h"

class String {
	char *str;
	int len;
public:
	String( );
	String(const char *s); 
	String(const String& copy);

	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+(const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);

	~String( );
};



#endif