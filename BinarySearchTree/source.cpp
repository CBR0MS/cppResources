/*****   HEADER:  driver.cpp   *****/

//Miakhau, Chia
//2/27/2017
//MS Visual C++ 2015
//File needed: BST_H.h
//Testing BST class template BST

#include "BSTh.h"
#include <iostream>
using namespace std;

int main()
{
	BST<int> myTree1;
	//for (int i = 0; i < 10; i++)
	//	myTree1.insert(i);

	myTree1.insert(55);
	myTree1.insert(20);
	myTree1.insert(90);
	myTree1.insert(54);
	myTree1.insert(60);
	myTree1.insert(1);
	myTree1.insert(100);
	myTree1.insert(52);
	myTree1.insert(50);
	myTree1.insert(45);
	myTree1.insert(64);
	myTree1.insert(68);
	myTree1.insert(80);

	cout << "TEST 1: Number Tree...\n";
	myTree1.inOrder();
	cout << endl;
	myTree1.preOrder();
	cout << endl;
	myTree1.postOrder();

	cout << "Delete 3\n";
	myTree1.deleteNum(20);
	myTree1.inOrder();

	//BST<char> myTree2;
	//for (int i = 0; i < 10; i++)
	//	myTree2.insert(static_cast<char> ('A' + i));
	//cout << "\nTEST 2: Character Tree...\n";
	//myTree2.inOrder();

	cout << endl;
	return 0;
}

