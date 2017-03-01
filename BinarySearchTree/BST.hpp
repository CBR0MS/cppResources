/*****   HEADER:  BST_H.h   *****/

//Christian Broms
//2/27/2017
//MS Visual C++ 2015
//Class template implementation: BST
#include <iostream>
#ifndef BSTh_h
#define BSTh_h

template <class T>
class BST
{
public:
	BST();

	void insert(T new_item);
	void deleteNum(T p_delete);
	void inOrder(); 
	void preOrder();
	void postOrder();

private:
	struct Node
	{
		T data;
		Node *llink = nullptr;
		Node *rlink = nullptr;
	};

	Node *m_root = nullptr;

	//Helper functions
	void helperInOrder(Node *ptr);
	void helperPreOrder(Node* node);
	void helperPostOrder(Node* node);
	bool isEnd(Node* node);
	
};

template <class T>
BST<T>::BST()
{
	m_root = nullptr;
}

template <class T>
void BST<T>::insert(T new_item)
{
	//Create the new node for insert item
	Node *temp = new Node;
	temp->data = new_item;
	temp->llink = nullptr;
	temp->rlink = nullptr;

	//Insert into an empty tree
	if (m_root == nullptr)
	{
		m_root = temp;
		return;
	}

	//1. 'trailPtr' trails right behind movPtr as it moves
	//	down to find the spot for insertion
	//	REASON: movPtr will become null at some point
	//		but we need the last node it last traversed to,
	//		in order to link up the new node.
	//2. 'left' boolean variable allows us to determine
	//	if we need to link the new node to the left of right 
	//	link of an existing node.

	Node *movPtr = m_root;
	Node *trailPtr = movPtr;
	bool left = true;
	while (movPtr != nullptr)
	{
		if (movPtr->data > new_item)
		{
			trailPtr = movPtr;
			movPtr = movPtr->llink;
			left = true;
		}
		else if (movPtr->data < new_item)
		{
			trailPtr = movPtr;
			movPtr = movPtr->rlink;
			left = false;
		}
		else if (movPtr->data == new_item)
			return;
	}

	//Choose left or right link to link up
	//	the new node pointed to by 'temp'
	if (left)
		trailPtr->llink = temp;
	else
		trailPtr->rlink = temp;

	temp = nullptr;
}

template<class T>
void BST<T>::deleteNum(T p_delete) {

	// find the node in the tree 
	Node* movPtr = m_root;

	while (movPtr != nullptr) {

		if (movPtr->data > p_delete) {

			movPtr = movPtr->llink;
		}
		else if (movPtr->data < p_delete) {

			movPtr = movPtr->rlink;
		}
		else if (movPtr->data == p_delete)
			break;
	}

	// check for case 1: node is endnode 
	if (isEnd(movPtr)) {

		// delete node and make parent endnode
		delete movPtr;
		movPtr = nullptr;
		// finished
	}
	else {

	// check for case 2: node has children

		while (!isEnd(movPtr)) {

			Node* temp = movPtr;
			// find next largest in list- once left, all the way to right
			temp = temp->llink;
			while (temp->rlink != nullptr) {
				temp = temp->rlink;
			}
			// swap values of largest and node to delete
			T tempData = movPtr->data;
			movPtr->data = temp->data;
			temp->data = tempData;

			// assign node to delete as next node down
			movPtr = movPtr->rlink;

			// repeat until node is an endnode
			// case 1

		}
		delete movPtr;
		movPtr = nullptr;
	}
}
template<class T>
bool BST<T>::isEnd(Node* node) {

	if (node->rlink == nullptr && node->llink == nullptr || node == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
	
template <class T>
void BST<T>::inOrder()
{
	helperInOrder(m_root);
}

template <class T>
void BST<T>::helperInOrder(Node *ptr)
{
	if (ptr != nullptr)
	{
		helperInOrder(ptr->llink);
		cout << ptr->data << ' ';
		helperInOrder(ptr->rlink);
	}
}

template <class T>
void BST<T>::preOrder()
{
	helperPreOrder(m_root);
}

template<class T>
void BST<T>::helperPreOrder(Node *node) {

	if (node != nullptr) {

		cout << node->data << ' ';
		helperPreOrder(node->llink);
		helperPreOrder(node->rlink);
	
	}
}

template <class T>
void BST<T>::postOrder()
{
	helperPostOrder(m_root);
}
template<class T>
void BST<T>::helperPostOrder(Node* node) {

	if (node != nullptr) {

		helperPreOrder(node->llink);
		helperPreOrder(node->rlink);
		cout << node->data << ' ';
	}
}

#endif /* BST_h */
