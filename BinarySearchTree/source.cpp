// File: BSTmain.cpp
// Additional Files: BSTh.hpp
// Created by Christian Broms on 2/27/17
// Compiler: Xcode 8.2.1

#include "BSTh.hpp"
#include <iostream>
using namespace std;

int main()
{
    BST<int> myTree1;
    for (int i = 0; i < 10; i++)
		myTree1.insert(i);
    
    cout << "TEST 1: Number Tree...\n";
	cout << "In order...\n";
    myTree1.inOrder();
    cout << endl;
	cout << "Pre order...\n";
    myTree1.preOrder();
    cout << endl;
	cout << "Post order...\n";
    myTree1.postOrder();
    
    cout << "\nDelete 5, 8...\n";
    myTree1.deleteNum(5);
	 myTree1.deleteNum(8);
    myTree1.inOrder();
	cout << endl;
    
    BST<char> myTree2;
    for (int i = 0; i < 10; i++)
    	myTree2.insert(static_cast<char> ('A' + i));
    cout << "\nTEST 2: Character Tree...\n";
	cout << "In order...\n";
	myTree2.inOrder();
	cout << endl;
	cout << "Pre order...\n";
	myTree2.preOrder();
	cout << endl;
	cout << "Post order...\n";
	myTree2.postOrder();
	
	cout << "\nDelete 'C', 'H'...\n";
	myTree2.deleteNum('C');
	myTree2.deleteNum('H');
	myTree2.inOrder();
    cout << endl;
    return 0;
}
