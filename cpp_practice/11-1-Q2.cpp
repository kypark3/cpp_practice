#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;


class Book {
private:
	char *title; // 책의 제목
	char *isbn; // 국제 표준 도서 번호
	int price;

public:
	Book(const char title[], const char isbn[], int _price) : price(_price) {
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}

	Book(Book& ref) : price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}


	Book& operator=(Book& ref) {
		delete []title;
		delete []isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}


	~Book() {
		delete[]title;
		delete[]isbn;
	}

	void ShowBookInfo() const {
		cout << "제목 : " << title << endl;
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

	EBook(EBook &ref) : Book(ref) {
		DRMkey = new char[strlen(ref.DRMkey) + 1];
		strcpy(DRMkey, ref.DRMkey);
	}


	EBook& operator=(EBook& ref) {
		Book::operator=(ref);
		delete[]DRMkey;
		DRMkey = new char[strlen(ref.DRMkey) + 1];
		strcpy(DRMkey, ref.DRMkey);
		return *this;
	}


	~EBook() {
		delete[]DRMkey;
	}
};

int main() {
	Book book1("좋은C++1", "555-12345-890-0", 20000);
	book1.ShowBookInfo();
	Book book2("좋은C++2", "555-12345-890-0", 21000);
	book2.ShowBookInfo( );
	book1 = book2;
	book1.ShowBookInfo( );

	Book book3 = book2;
	book3.ShowBookInfo( );


	EBook ebook1("좋은C++ ebook1", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook1.ShowBookInfo();
	EBook ebook2("좋은C++ ebook2", "555-12345-890-1", 11000, "fdx9w0i8kiw");
	ebook2.ShowBookInfo( );
	ebook1 = ebook2;
	ebook1.ShowBookInfo( );

	EBook ebook3 = ebook2;
	ebook3.ShowBookInfo( );

}


