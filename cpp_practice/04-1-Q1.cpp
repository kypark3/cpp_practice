#include <iostream>

/*
const 선언을 통해 코드 안정화 (멤버 변수가 바뀌지 않아야 하는 곳에 const 선언)
0보다 작은 돈이 들어왔을 때 예외처리
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
			cout << "잘못된 돈이 입력되었습니다." << endl << endl;
			return 0;
		}

	}

	void ShowSalesResult() const {
		cout << "남은 사과 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMoney << endl << endl;
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
			cout << "잘못된 돈이 입력되었습니다." << endl << endl;
		}
	}

	void ShowBuyResult() const {
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numOfApples << endl << endl;
	}
};

int main() {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "--판매자 현황--" << endl;
	buyer.ShowBuyResult();
	
	cout << "--구매자 현황--" << endl;
	seller.ShowSalesResult();

	return 0;
}


