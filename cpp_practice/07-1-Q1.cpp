#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;


class Car {
	int gasolineGauge;
public:
	Car(int _gasolineGauge) : gasolineGauge(_gasolineGauge) {
		cout << "Car create" << endl;
	}

	~Car() {
		cout << "Car delete" << endl;
	}

	int GetGasGague() const {
		return gasolineGauge;
	}

};

class HybridCar : public Car {
	int electricGauge;
public:

	HybridCar(int _gasolineGague, int _electricGauge) : Car(_gasolineGague), electricGauge(_electricGauge) {
		cout << "HybridCar create" << endl;
	}

	~HybridCar() {
		cout << "HybridCar delete" << endl;
	}

	int GetElecGauge() const {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
	int waterGauge;
public:

	HybridWaterCar(int _gasolineGague, int _electricGauge , int _waterGauge) : HybridCar(_gasolineGague , _electricGauge ), waterGauge(_waterGauge){
		cout << "HybridWaterCar create" << endl;
	}

	~HybridWaterCar() {
		cout << "HybridWaterCar delete" << endl;
	}

	void ShowCurrentGauge() const {
		cout << "ÀÜ¿© °¡¼Ö¸° : " << GetGasGague() << endl;
		cout << "ÀÜ¿© Àü±â·® : " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·® : " << waterGauge << endl;

	}
};

int main() {

	HybridWaterCar HWC1(100, 200, 300);
	HybridWaterCar HWC2(50,100,150);

	HWC1.ShowCurrentGauge();
	HWC2.ShowCurrentGauge();

	return 0;
}
