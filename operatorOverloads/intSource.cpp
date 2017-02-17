#include <iostream>
#include "intItemH.h"

using namespace std;

int main()
{

	IntItem obj1;
	IntItem obj2;

	cout << "TEST 1: >> operator\n";
	cout << "Enter the first integer item: ";
	cin >> obj1;
	cout << "Enter the second integer item: ";
	cin >> obj2;

	cout << "\nTEST 2: << operator\n";
	cout << "Obj1 by overloaded insertion operator " << obj1 << endl;
	cout << "Obj2 by overloaded insertion operator " << obj2 << endl;

	cout << "\nTEST 3: binary +\n";
	cout << "obj1 + obj2 = " << obj1 + obj2 << endl;
	cout << "Current value of obj1 = " << obj1 << endl;
	cout << "Current value of obj2 = " << obj2 << endl;

	cout << "\nTEST 4: pre-increment ++\n";
	cout << "++obj1 + obj2 = " << ++obj1 + obj2 << endl;
	cout << "Current value of obj1 = " << obj1 << endl;
	cout << "Current value of obj2 = " << obj2 << endl;

	cout << "\nTEST 5: post-increment ++\n";
	cout << "obj1 + obj2++ = " << obj1 + obj2++ << endl;
	cout << "Current value of obj1 = " << obj1 << endl;
	cout << "Current value of obj2 = " << obj2 << endl;

	cout << "\n\nQuestion: Why is this possible?" << endl;
	cout << "obj1 + obj2 + obj1 + obj2 + obj1 = "
		<< obj1 + obj2 + obj1 + obj2 + obj1 << endl;

	cout << endl;

	return 0;
}
