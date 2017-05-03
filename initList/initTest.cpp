#include <iostream>
#include <initializer_list>
#include "MyStack.h"

using namespace std;

int main() {


	cout << "Integer stack...\n";
	MyStack<int> stk1;

	for (int i = 0; i < 10; i++)
		stk1.push(i + 1);

	for (int i = 0; i < 10; i++)
	{
		cout << stk1.top() << ' ';
		stk1.pop();
	}

	cout << "\nFloating-point stack...\n";
	MyStack<double> stk2;
	for (int i = 0; i < 10; i++)
		stk2.push(1.5 * (i + 1));

	for (int i = 0; i < 10; i++)
	{
		cout << stk2.top() << ' ';
		stk2.pop();
	}

	cout << "\nCharacter stack constructed with C++11 initializer list...\n";
	MyStack<char> stk3{ 'C', 'O', 'M', 'P', ' ', '3', '6', '5' };

	for (int i = 0; i < 8; i++)
	{
		cout << stk3.top() << ' ';
		stk3.pop();
	}

	return 0;
}
