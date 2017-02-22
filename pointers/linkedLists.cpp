// Filename: node.cpp
// Last edit by Christian Broms on 2/22/17
// Compiler: Xcode 8.2.1

#include <iostream>

struct Node {

	int data;
	Node* link;
};

void makeNodeList (Node*& hPtr, Node*& tPtr, Node*& temp);	// constructs a new node list
void makeNode (int p_data, Node*& hPtr, Node*& temp);		// constructs a new node and adds to the list
void printListData (Node*& hPtr, Node*& temp);			// prints the data from the list

int main() {

	Node* hPtr = nullptr;
	Node* tPtr = nullptr;
	Node* temp = nullptr;
	hPtr = new Node;
	tPtr = new Node;
	temp = new Node;

	makeNodeList(hPtr, tPtr, temp);

	makeNode(32, hPtr, temp);
	makeNode(12, hPtr, temp);
	makeNode(56, hPtr, temp);
	makeNode(1, hPtr, temp);
	makeNode(99, hPtr, temp);
	makeNode(25, hPtr, temp);

	printListData(hPtr, temp);

	return 0;
}

// constructs a node list with a head and tail pointer
// data members are INT_MIN and INT_MAX, respectively

void makeNodeList(Node*& hPtr, Node*& tPtr, Node*& temp) {

	// populate first node (dummy)
	hPtr->data = INT_MIN;
	hPtr->link = nullptr;
	tPtr = hPtr;
	
	// populate last node (dummy)
	tPtr->link = temp;
	temp->data = INT_MAX;
	temp->link = nullptr;
	tPtr = temp;
}

// adds a new node to the list, placed based on data 
// member, in ascending order

void makeNode(int p_data, Node*& hPtr, Node*& temp) {

	temp = new Node;
	temp->data = p_data;
	temp->link = nullptr;

	Node* mPtr = nullptr;
	Node* prior = nullptr;
	bool cont = true;

	mPtr = hPtr;

	while (cont) {

		if (mPtr->data < temp->data) {

			prior = mPtr;
			mPtr = mPtr->link;
		}
		else {
			cont = false;
		}
	}
	temp->link = prior->link;
	prior->link = temp;
}

// display everything that is not INT_MAX or INT_MIN

void printListData (Node*& hPtr, Node*& temp) {

	temp = hPtr;

	while (temp != nullptr) {

		if (temp->data != INT_MAX && temp->data != INT_MIN) {

			std::cout << temp->data << ' ';
		}
		temp = temp->link;
	}
}
