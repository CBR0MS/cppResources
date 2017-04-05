// File: Administrator.cpp

#include <iostream>
#include <string>
#include "Administrator.hpp"

using namespace std;
using namespace adm;

Administrator::Administrator()
: SalariedEmployee()
{
    // deliberately empty
}
Administrator::Administrator(const string& theName, const string& theSsn, double theWeeklySalary,
                             const string& theTitle, const string& theSupervisor, const string& theResponsibility)
: SalariedEmployee(theName, theSsn, theWeeklySalary), supervisor(theSupervisor),
title(theTitle), responsiblity(theResponsibility)
{
    // deliberately empty
}
void Administrator::inputData() {
    
    // we want to input all the parameters of the contructor one by one
    cout << "Enter Name: ";
    string name;
    cin >> name;
    SalariedEmployee::setName(name);
    cout << "Enter SSN: ";
    string ssn;
    cin >> ssn;
    SalariedEmployee::setSsn(ssn);
    cout << "Enter Weekly Salary: ";
    double salary = 0;
    cin >> salary;
    SalariedEmployee::setSalary(salary);
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
    
    // because the check is printed for a month, we'll multiply the weekly salary by four
    Employee::setNetPay(SalariedEmployee::getSalary() * 4);
    
    // print all the administrator information
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
