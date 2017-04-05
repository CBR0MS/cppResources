#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <string> 
#include <iostream> 
#include "SalariedEmployee.h"

namespace adm {

	class Administrator : public semp::SalariedEmployee {

	public:

		Administrator();
		Administrator(const string& theName, const string& theSsn, double theWeeklySalary,
			const string& theTitle, const string& theSupervisor, const string& theResponsibility);
		void inputData();
		void setSupervisor(const string& supName);
		void print();
		void printCheck();

	protected:
		double salary;

	private:
		string title;
		string responsiblity;
		string supervisor;
	};
}
#endif 
