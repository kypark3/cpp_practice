#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

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
		cout << "My name is " << name << endl;
	}

	virtual int GetPay() const = 0; // ���� �����Լ� : �Լ��� ��ü�� ���ǵ��� �ʰ��� ���� Ŭ������ �������� �ʰԵǹǷ� ��ü�� �������� ����.
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
	SalesWorker(const char _name[], int _salary, int _salseResult ,double _bonusRatio) : PermanentWorker(_name, _salary), salseResult(_salseResult) , bonusRatio(_bonusRatio){ }

	virtual int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salseResult * bonusRatio);
	}

	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "SalesWorker salary : " << GetPay() << endl;
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
			empList[i]->ShowSalaryInfo();
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
	emphadler.AddEmployee(new PermanentWorker("pky1" , 1000));
	emphadler.AddEmployee(new PermanentWorker("pky2", 2000));
	emphadler.AddEmployee(new SalesWorker("pky3", 1000, 1000 , 1.5));
	emphadler.AddEmployee(new SalesWorker("pky4", 2000, 1000, 0.5));

	emphadler.ShowTotalSalary();
	cout << endl;
	emphadler.ShowAllempList();

	//Employ *test = new Employ("pky"); // ���� �����Լ��� �������� �ʱ� ������ ��ü ������ ����

	return 0;
}