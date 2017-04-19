// Stack.hpp

#pragma once

class Stack {

public:
	Stack() { };
	void pop() { size--; };
	void push(int pos) { size++; };
	int size = 0;
};


// PushToFullStackException.hpp

#pragma once
#include <string>
#include <iostream>

using namespace std;

class PushToFullStackException {

public:
	PushToFullStackException() { };
	PushToFullStackException(string p_message) { message = p_message; };
	void what() { cout << message; };
	string message;
};

// Driver.cpp

#include <iostream>
#include <string>
#include "Stack.hpp"
#include "PushToFullStackException.hpp"

using namespace std;

int main() {

	bool cond = true;
	bool firstTry = true;

// TODO: get rid of while and add a second try
	while (cond) {

		try {

			Stack myStk; //Capacity of 3

			for (int i = 0; i < 5; i++) {

				// try to manipulate the stack
				if (i == 0 && firstTry) {
					firstTry = false;
					cout << "Popping right away.\n";
					myStk.pop();
				}
				else {
					cout << "\nPushing " << i + 1 << "st item.\n";
					myStk.push(i);
				}

				// now check
				if (myStk.size < 0) {
					cond = false;
					throw PushToFullStackException("Exception: your stack is empty!\n");
				}
				if (myStk.size > 3) {
					cond = false;
					throw PushToFullStackException("Exception: your stack is full!\n");
				}
			}

		}
		catch (PushToFullStackException e) {

			e.what();
			cout << "\nEnter 1 to continue...";
			string inp;
			cin >> inp;

			if (inp == "1") {
				cond = true;
			}
			else {
				cond = false;
			}
		}
	}
	
	return 0;
}
