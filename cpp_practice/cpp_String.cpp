#include "cpp_String.h"

String::String( ) {
	str = NULL;
	len = 0;
}

String::String(const char *s) {
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

String::String(const String& copy) {
	len = copy.len;
	str = new char[len + 1];
	strcpy(str, copy.str);
}

String& String::operator=(const String &s) {
	if (str != NULL) {
		delete[]str;
	}

	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s) {
	len += s.len;
	char *tmp= new char[len + 1];
	strcpy(tmp, str);
	strcat(tmp, s.str);

	if (str != NULL) {
		delete[]str;
	}
	str = tmp;
	return *this;
}


bool String::operator==(const String& s) {
	return !strcmp(str, s.str);
}

String String::operator+(const String& s) {
	char *tmp = new char[len + s.len + 1];
	strcpy(tmp, str);
	strcat(tmp, s.str);
	String tmpstr(tmp);
	delete[]tmp;
	return tmpstr;
}

ostream& operator<<(ostream &os, const String& s) {
	os << s.str;
	return os;
}

istream& operator>>(istream &is, String& s) {
	char tmp[1000];
	is >> tmp;
	s = String(tmp);
	return is;
}

String::~String( ) {
	if (str != NULL) {
		delete[]str;
	}
}

