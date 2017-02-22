// Filename: node.cpp
// Last edit by Christian Broms on 2/18/17
// Compiler: Xcode 8.2.1

#include <iostream>

struct Node {

	int data;
	Node* link;
};

void makeNodeList(Node*& hPtr, Node*& tPtr);	// constructs a new node list
void makeNode(int p_data, Node* hPtr);		// constructs a new node
void insertNode(Node* data, Node* hPtr);	// adds a node to the list
void printListData(Node* hPtr);			// prints the data from the list

int main() {

	Node* hPtr = nullptr;
	Node* tPtr = nullptr;

	makeNodeList(hPtr, tPtr);

	makeNode(32, hPtr);
	makeNode(12, hPtr);
	makeNode(56, hPtr);
	makeNode(1, hPtr);
	makeNode(99, hPtr);
	makeNode(25, hPtr);

	printListData(hPtr);

	return 0;
}

void makeNodeList(Node*& hPtr, Node*& tPtr) {

	// make and populate first node (dummy)

	hPtr = new Node;
	hPtr->data = INT_MIN;
	hPtr->link = nullptr;
	tPtr = hPtr;

	// make and populate last node (dummy)

	Node* temp = nullptr;
	temp = new Node;
	tPtr->link = temp;
	temp->data = INT_MAX;
	temp->link = nullptr;
	tPtr = temp;
}

void makeNode(int p_data, Node* hPtr) {

	Node* temp;
	temp = new Node;
	temp->data = p_data;
	temp->link = nullptr;
	insertNode(temp, hPtr);
	temp = nullptr;
}


void insertNode(Node* insert, Node* head) {

	Node* mPtr = nullptr;
	Node* prior = nullptr;
	bool cont = true;

	mPtr = head;

	// insterted according to node's int member

	while (cont) {

		if (mPtr->data < insert->data) {

			prior = mPtr;
			mPtr = mPtr->link;
		}
		else {
			cont = false;
		}
	}

	insert->link = prior->link;
	prior->link = insert;
}

void printListData(Node* hPtr) {

	Node* temp = nullptr;
	temp = hPtr;

	// display everything that is not INT_MAX or INT_MIN

	while (temp != nullptr) {

		if (temp->data != INT_MAX && temp->data != INT_MIN) {

			std::cout << temp->data << std::endl;
		}

		temp = temp->link;
	}

	temp = nullptr;
}
