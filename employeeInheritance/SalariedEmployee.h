#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H
#include <string> 
#include "Employee.h" 

namespace semp {

	class SalariedEmployee: public emp::Employee
	{
	public:

		SalariedEmployee();
		SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary);
		double getSalary() const;
		void setSalary(double newSalary);
		void printCheck();

	protected:
		double salary; // weekly 
	};

}

#endif
