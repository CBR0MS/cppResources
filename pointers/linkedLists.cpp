#include <iostream>

using namespace std;

struct Node {

	int data;
	Node* link;
};

void insertNode(Node* data, Node* hPtr);

int main() {

	Node* hPtr = NULL;
	Node* tPtr = NULL;
	Node* temp = NULL;
	Node* mPtr = NULL;

	// make and populate first node (dummy)

	hPtr = new Node;
	hPtr->data = INT_MIN;
	hPtr->link = NULL;
	tPtr = hPtr;

	// make and populate the center nodes

	for (int i = 10; i <= 40; i += 10) {

		temp = new Node;
		tPtr->link = temp;
		temp->data = i;
		temp->link = NULL;
		tPtr = temp;
	}

	// make and populate last node (dummy)

	temp = new Node;
	tPtr->link = temp;
	temp->data = INT_MAX;
	temp->link = NULL;
	tPtr = temp;

	// add new nodes 

	temp = new Node;
	temp->data = 25;
	temp->link = NULL;

	insertNode(temp, hPtr);

	temp = new Node;
	temp->data = 1;
	temp->link = NULL;

	insertNode(temp, hPtr);

	temp = new Node;
	temp->data = 99;
	temp->link = NULL;

	insertNode(temp, hPtr);

	// display

	temp = hPtr;

	while (temp != NULL) {

		if (temp->data != INT_MAX && temp->data != INT_MIN) {

			cout << temp->data << endl;
		}

		temp = temp->link;
	}

	return 0;
}

// insert passed node into linked list

void insertNode(Node* insert, Node* head) {

	Node* mPtr = NULL;
	Node* prior = NULL;
	bool cont = true;

	mPtr = head;

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
