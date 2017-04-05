#include <iostream> 
#include <string> 
#include "SalariedEmployee.h" 

using namespace std;
using namespace semp;

SalariedEmployee::SalariedEmployee()
	: Employee(), salary(0)
{
	// deliberately empty 
}
SalariedEmployee::SalariedEmployee(const string& theName,
	const string& theNumber, double theWeeklyPay)
	: Employee(theName, theNumber), salary(theWeeklyPay)
{
	// deliberately empty 
}
double SalariedEmployee::getSalary() const
{
	return salary;
}
void SalariedEmployee::setSalary(double newSalary)
{
	salary = newSalary;
}
void SalariedEmployee::printCheck()
{
	Employee::setNetPay(salary * 52);
	cout << "\n________________________________________________\n";
	cout << " Pay to the order of " << Employee::getName() << endl;
	cout << " The sum of " << Employee::getNetPay() << " Dollars\n";
	cout << "_________________________________________________\n";
	cout << " Check Stub NOT NEGOTIABLE \n";
	cout << " Employee Number: " << Employee::getSsn() << endl;

	cout << " Salaried Employee. Regular Pay: "
		<< salary << endl;
	cout << "_________________________________________________\n";

}
