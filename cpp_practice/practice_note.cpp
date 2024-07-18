#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

class Person {
	char *name;
	int age;
public:
	Person(const char name[], int age) {
		cout << "create Person" << endl;
		int name_len = strlen(name) + 1;
		this->name = new char[name_len];
		strcpy(this->name, name);
		this->age = age;
	}

	Person() {
		this->name = NULL;
		this->age = 0;
	}

	~Person() {
		delete[]name;
	}

	void initPerson(const char name[], int age);
	void ShowPersonInfo() const;
};

void Person::initPerson(const char name[], int age) {
	cout << "class function create Peroon" << endl;
	int name_len = strlen(name) + 1;
	this->name = new char[name_len];
	strcpy(this->name, name);
	this->age = age;
}



void Person::ShowPersonInfo() const {
	cout << "name : " << name << endl;
	cout << "age : " << age << endl;
}

int main() {

	int person_num = 3;
	Person *persons = new Person[person_num];
	
	for (int i = 0; i < person_num; i++) {
		int	newage;
		char newname[100];
		cin >> newname >> newage;
		int len = strlen(newname) + 1;
		persons[i].initPerson(newname, newage);
	}

	for(int i =0 ; i< person_num; i++)
	persons[i].ShowPersonInfo();

	delete[]persons;
	
	return 0;
}