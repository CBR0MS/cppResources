#include <iostream>
#include <string>
#include "Administrator.h"

using namespace std;
using namespace adm;

Administrator::Administrator()
	: SalariedEmployee()
{ 
	// empty
}
Administrator::Administrator(const string& theName, const string& theSsn, double theWeeklySalary,
	const string& theTitle, const string& theSupervisor, const string& theResponsibility) 
	: SalariedEmployee(theName, theSsn, theWeeklySalary), supervisor(theSupervisor),
	title(theTitle), responsiblity(theResponsibility)
{
	// empty
}
void Administrator::inputData() {

	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter SSN: ";
	cin >> ssn;
	cout << "Enter Weekly Salary: ";
	cin >> salary;
	cout << "Enter Title: ";
	cin >> title;
	cout << "Enter Responsiblity: ";
	cin >> responsiblity;
	cout << "Enter Supervisor: ";
	cin >> supervisor;
	cout << endl;
}
void Administrator::setSupervisor(const string& supName) {

	supervisor = supName;
}
void Administrator::print() {

	Employee::setNetPay(SalariedEmployee::getSalary() * 52);
	cout << "Name: " << Employee::getName() << endl;
	cout << "SSN: " << Employee::getSsn() << endl;
	cout << "Net Pay : " << Employee::getNetPay() << endl;
	cout << "Weekly Salary: " << SalariedEmployee::getSalary () << endl;
	cout << "Title: " << title << endl;
	cout << "Responsibility: " << responsiblity << endl;
	cout << "Supervisor: " << supervisor << endl;
}
void Administrator::printCheck() {
	
	SalariedEmployee::printCheck();
}
