// Racing Car 최종버전
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

namespace CAR_CONST {
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STPE = 10
	};
}

struct Car {
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();
};

void Car::Accel() {
	if (fuelGauge <= 0) return;
	else fuelGauge -= CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::ShowCarState() {
	cout << "소유자 ID : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << "%" << endl;
	cout << "현재속도 : " << curSpeed << "km/s" << endl << endl;
}

void Car::Break() {

	if (curSpeed - CAR_CONST::BRK_STPE <= 0) curSpeed = 0;
	else curSpeed -= CAR_CONST::BRK_STPE;

}

int main() {

	Car run99 = { "run99", 100,0 };
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	return 0;
}
