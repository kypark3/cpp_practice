#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;


class Book {
private:
	char *title; // å�� ����
	char *isbn; // ���� ǥ�� ���� ��ȣ
	int price;

public:
	Book(const char title[], const char isbn[], int _price) : price(_price) {
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}

	~Book() {
		delete[]title;
		delete[]isbn;
	}

	void ShowBookInfo() const {
		cout << "���� : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "price : " << price << endl << endl;
	}
};

class EBook : public Book {
private:
	char *DRMkey;
public:
	EBook(const char title[], const char isbn[], int _price, const char DRMkey[]) :Book(title, isbn, _price) {
		this->DRMkey = new char[strlen(DRMkey) + 1];
		strcpy(this->DRMkey, DRMkey);
	}

	~EBook() {
		delete[]DRMkey;
	}
};

int main() {
	Book book("����C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();

	EBook ebook("����C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowBookInfo();
}


