#include <iostream>

/*
const ������ ���� �ڵ� ����ȭ (��� ������ �ٲ��� �ʾƾ� �ϴ� ���� const ����)
0���� ���� ���� ������ �� ����ó��
*/

using std::cin;
using std::cout;
using std::endl;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	
	int SaleApples(int money) {
		if (money > 0) {
			int num = money / APPLE_PRICE;
			numOfApples -= num;
			myMoney += money;
			return num;
		}
		else {
			cout << "�߸��� ���� �ԷµǾ����ϴ�." << endl << endl;
			return 0;
		}

	}

	void ShowSalesResult() const {
		cout << "���� ��� : " << numOfApples << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl << endl;
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller &seller, int money) {
		if (money > 0) {
			numOfApples += seller.SaleApples(money);
			myMoney -= money;
		}
		else {
			cout << "�߸��� ���� �ԷµǾ����ϴ�." << endl << endl;
		}
	}

	void ShowBuyResult() const {
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
};

int main() {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "--�Ǹ��� ��Ȳ--" << endl;
	buyer.ShowBuyResult();
	
	cout << "--������ ��Ȳ--" << endl;
	seller.ShowSalesResult();

	return 0;
}


