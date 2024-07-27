#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

namespace RISK_LEVEL {
	enum {
		RISK_A = 30, RISK_B = 20 , RISK_C = 10
	};
}

class Employ {
private:
	char *name;

public:
	Employ(const char _name[]) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	~Employ() {
		delete[]name;
	}


	void ShowYourName() const {
		cout << "name : " << name << endl;
	}

	virtual int GetPay() const = 0; // 순수 가상함수 : 함수의 몸체가 정의되지 않게함 따라서 클래스가 완전하지 않게되므로 객체를 생성하지 못함.
	virtual void ShowSalaryInfo() const = 0;

};

class PermanentWorker : public Employ {
private:
	int salary;
public:
	PermanentWorker(const char _name[], int _salary) : Employ(_name), salary(_salary) {	}

	virtual int GetPay() const { return salary; }

	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "PermanentWorker salary : " << GetPay() << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salseResult;
	double bonusRatio;

public:
	SalesWorker(const char _name[], int _salary, double _bonusRatio) : PermanentWorker(_name, _salary), salseResult(0), bonusRatio(_bonusRatio) { }

	void AddSalesResult(int value) {
		salseResult += value;
	}

	virtual int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salseResult * bonusRatio);
	}

	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "SalesWorker salary : " << GetPay() << endl;
	}

};

class ForeignSalesWorker : public SalesWorker {
private:
	int risk;
public:
	ForeignSalesWorker(const char _name[], int _salary, double _bonusRatio, int _risk) : SalesWorker(_name, _salary , _bonusRatio) , risk(_risk){ }

	virtual int GetPay() const {
		return GetRiskPay() + SalesWorker::GetPay();
	}

	int GetRiskPay() const {
		return (int)(SalesWorker::GetPay() * risk / 100);
	}

	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << SalesWorker::GetPay() << endl;
		cout << "risk pay : " << GetRiskPay()<< endl;
		cout << "ForeignSalseWorker pay : " <<  GetPay() << endl;
	}
};

class EmployeeHandler {
private:
	Employ *empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0) {}

	void AddEmployee(Employ *emp) {
		empList[empNum++] = emp;
	}

	void ShowTotalSalary() const {

		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}

		cout << "Total salary : " << sum << endl;
	}

	void ShowAllempList() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo(); cout << endl;
		}
	}

	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main() {

	EmployeeHandler emphadler;
	ForeignSalesWorker *f1 = new ForeignSalesWorker("pky1", 1000, 0.1, RISK_LEVEL::RISK_A);
	f1->AddSalesResult(7000);
	emphadler.AddEmployee(f1);

	ForeignSalesWorker *f2 = new ForeignSalesWorker("pky2", 1000, 0.1, RISK_LEVEL::RISK_B);
	f2->AddSalesResult(7000);
	emphadler.AddEmployee(f2);

	ForeignSalesWorker *f3 = new ForeignSalesWorker("pky3", 1000, 0.1, RISK_LEVEL::RISK_C);
	f3->AddSalesResult(7000);
	emphadler.AddEmployee(f3);

	emphadler.ShowAllempList();
	emphadler.ShowTotalSalary();
	return 0;
}