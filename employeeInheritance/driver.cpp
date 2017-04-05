#include <iostream>
#include <string>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"

using namespace std;
using namespace emp;
using namespace semp;
using namespace adm;

int main()
{
	//SalariedEmployee();
	SalariedEmployee employeeA;
	//SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary);
	SalariedEmployee employeeB("Elisa", "123-45-6789", 1500);
	//double getSalary() const;
	cout << "******************** Salaried Employee A ********************\n";
	cout << "Name =\t" << employeeA.getName() << endl;
	cout << "Net Pay =\t" << employeeA.getNetPay() << endl;
	cout << "Salary =\t" << employeeA.getSalary() << endl;
	cout << "Social Security number =\t" << employeeA.getSsn() << endl;
	cout << "Pay Check...\n";
	employeeA.printCheck();

	cout << "\n\n**********************************************************\n";
	cout << "\n!!! Updating name, salary, ssn for salaried employee A !!!\n";
	cout << "\n**********************************************************\n";
	employeeA.setName("John");
	employeeA.setSsn("987-65-4321");
	employeeA.setNetPay(90000);
	employeeA.setSalary(120000);

	cout << "\n\n*************** UPDATED Salaried Employee A *****************\n";
	cout << "Name =\t" << employeeA.getName() << endl;
	cout << "Net Pay =\t" << employeeA.getNetPay() << endl;
	cout << "Salary =\t" << employeeA.getSalary() << endl;
	cout << "Social Security number =\t" << employeeA.getSsn() << endl;
	cout << "Pay Check...\n";
	employeeA.printCheck();

	cout << "\n\n******************** Salaried Employee B ********************\n";
	cout << "Name =\t" << employeeB.getName() << endl;
	cout << "Net Pay =\t" << employeeB.getNetPay() << endl;
	cout << "Salary =\t" << employeeB.getSalary() << endl;
	cout << "Social Security number =\t" << employeeB.getSsn() << endl;
	cout << "Pay Check...\n";
	employeeB.printCheck();

	cout << "\n\n******************** Adminstrator Employee C ********************\n";
	Administrator employeeC;
	employeeC.inputData();
	employeeC.print();
	//cout << "Name =\t" << employeeC.getName() << endl;
	//cout << "Net Pay =\t" << employeeC.getNetPay() << endl;
	//cout << "Salary =\t" << employeeC.getSalary() << endl;
	//cout << "Social Security number =\t" << employeeC.getSsn() << endl;
	//cout << "Pay Check...\n";
	employeeC.printCheck();

	cout << endl;
	return 0;
}
