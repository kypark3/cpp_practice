#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;

class Person {

private:
	char *name;
	int age;

public:
	Person(char _name[], int _age) : age(_age) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	Person(Person& p1) :age(p1.age){
		name = new char[strlen(p1.name) + 1];
		strcpy(name, p1.name);
	}

	//person3.operator=(person2);
	//person3 = person2;
	Person& operator=(Person &p) {
		delete[]name;
		age = p.age;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
		return *this;
	}
	~Person( ) {
		delete[]name;
	}
};


int main() {

	Person p1("pky", 13);
	Person p2 = p1; // 복사생성자
	Person p3("none", 0);
	p3 = p2; // operator

	return 0;
}