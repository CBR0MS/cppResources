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
    
    Stack myStk;
    
    try{
    
        cout << "Popping right away.\n";
        myStk.pop();
        
        if (myStk.size < 0) {
            throw PushToFullStackException("Exception: your stack is empty!\n\n");
        }
    }
    catch (PushToFullStackException e) {
        
        e.what();
    }
    try{
        
        for (int i = 1; i < 5; i++){
            
            cout << "Pushing " << i  << "st item.\n";
            myStk.push(i);
            
            if (myStk.size >= 3) {
                throw PushToFullStackException("Exception: your stack is full!\n\n");
            }
        }
        
    }
    catch (PushToFullStackException e) {
        
        e.what();
    }
    
    return 0;
}
