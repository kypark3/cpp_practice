#include <iostream>
#include <cstdlib>
#pragma warning(disable:4996);
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::cin;

class string {
private:
	char *str;

public:
	string(const char _str[]) {
		str = new char[strlen(_str) + 1];
		strcpy(str, _str);
	}

	string(string& copy) {
		str = new char[strlen(copy.str) + 1];
		strcpy(str, copy.str);
	}

	string& operator=(string& copy) {
		delete[]str;
		str = new char[strlen(copy.str) + 1];
		strcpy(str, copy.str);
		return *this;
	}
	//str1.operator+(str2);
	string operator+(string& addstring) {
		
		char *addstr = new char[strlen(str) + strlen(addstring.str) + 1];
		strcpy(addstr, str);
		strcat(addstr, addstring.str);

		string retstring(addstr);
		delete[]addstr;
		return retstring;
	}

	string& operator+=(string& addstring) {
		
		char *addedstr = new char[strlen(str) + strlen(addstring.str) + 1];
		strcpy(addedstr, str);
		strcat(addedstr, addstring.str);
		delete[]str;
		str = addedstr;
		return *this;
	}

	//str1 == str2 // str1.operator==(str2)
	bool operator==(string &comparestring) {

		if (strlen(str) != strlen(comparestring.str)) {
			return false;
		}

		for (int i = 0; i < strlen(str); i++) {
			if (str[i] != comparestring.str[i]) {
				return false;
			}
		}

		return true;
	}

	friend ostream& operator<<(ostream& os, string& st) {
		os << st.str;
		return os;
	}


	friend istream& operator>>(istream& is, string& st) {
		char temp[1000];
		is >> temp;
		st = string(temp);
		return is;

	}

	void show( ) const {
		cout << str << endl;
	}

	~string( ) {
		delete[]str;
	}
};

int main( ) {

	string s1 = "str 1 ";
	string s2 = "str 2 ";
	string s3 = "none!";
	string s4 = s1 + s2;
	
	string s5("");
	string s6("");

	s3 = s1 + s2;
	s3.show( );

	s1 = s3;
	if (s1 == s3) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cout << s1 << s2 << endl;
	cin >> s5 >> s6;
	s5.show( );
	s6.show( );

	return 0;
}