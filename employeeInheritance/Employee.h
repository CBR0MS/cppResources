#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string> 
#include <iostream> 

using namespace std;

namespace emp {

	class Employee 
	{
	public:
		Employee();
		Employee(const string& theName, const string& theSsn);
		string getName() const;
		string getSsn() const;
		double getNetPay() const;
		void setName(const string& newName);
		void setSsn(const string& newSsn);
		void setNetPay(double newNetPay);
		void printCheck() const;

	protected:
		std::string name;
		std::string ssn;
		double netPay;
	};

}

#endif
