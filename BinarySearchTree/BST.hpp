// File: BSTh.hpp
// Additional Files: BSTmain.cpp
// Created by Christian Broms on 2/27/17
// Compiler: Xcode 8.2.1

#include <iostream>

#ifndef BSTh_hpp
#define BSTh_hpp

template<class T>
class BST {

public:

	/* CONSTRUCTOR */
	BST();

	/* ACESSORS & MUTATORS */
	void insert(T new_item);
	void deleteNum(T p_delete);
	void inOrder();
	void preOrder();
	void postOrder();

private:

	struct Node {

		T data;
		Node *llink = nullptr;
		Node *rlink = nullptr;
	};

	Node *m_root;

	/* PRIVATE HELPER FUNCTIONS */
	void helperInOrder(Node *ptr);
	void helperPreOrder(Node* node);
	void helperPostOrder(Node* node);
	Node* deleteNode(Node *node, int p_data);
	Node* findMin(Node* node);

};

/* DEFINITIONS */

template <class T>
BST<T>::BST() {

	m_root = nullptr;
}

template <class T>
void BST<T>::insert(T new_item) {

	// create the new node for insert item
	Node *temp = new Node;
	temp->data = new_item;
	temp->llink = nullptr;
	temp->rlink = nullptr;

	// insert into an empty tree
	if (m_root == nullptr) {

		m_root = temp;
		return;
	}

	Node *movPtr = m_root;
	Node *trailPtr = movPtr;
	bool left = true;

	while (movPtr != nullptr) {

		if (movPtr->data > new_item) {

			trailPtr = movPtr;
			movPtr = movPtr->llink;
			left = true;
		}
		else if (movPtr->data < new_item) {

			trailPtr = movPtr;
			movPtr = movPtr->rlink;
			left = false;
		}
		else if (movPtr->data == new_item)
			return;
	}

	// choose left or right link to link up
	// the new node pointed to by 'temp'
	if (left)
		trailPtr->llink = temp;
	else
		trailPtr->rlink = temp;

	temp = nullptr;
}

template<class T>
void BST<T>::deleteNum(T p_delete) {

	deleteNode(m_root, p_delete);
}

template<class T>
typename BST<T>::Node*  BST<T>::deleteNode(Node *node, int p_data) {

	if (node == nullptr) {

		// task complete
		return node;
	}

	else if (p_data < node->data) {

		// try the left link
		node->llink = deleteNode(node->llink, p_data);
	}
	else if (p_data > node->data) {

		// try the right link
		node->rlink = deleteNode(node->rlink, p_data);
	}
	else {

		if (node->llink == nullptr && node->rlink == nullptr) {

			// the node is a leaf node
			delete node;
			node = NULL;
		}
		else if (node->llink == nullptr) {

			// no left node, continue right
			node = node->rlink;
		}
		else if (node->rlink == nullptr) {

			// no right node, continue left
			node = node->llink;
		}
		else {

			// find the smallest node on the right branch and swap data fields
			// alternatively, we could find the largest on the left branch
			Node *temp = findMin(node->rlink);
			node->data = temp->data;
			node->rlink = deleteNode(node->rlink, temp->data);
		}
	}
	return node;
}

template<class T>
typename BST<T>::Node* BST<T>::findMin(Node* node) {

	while (node->llink != nullptr) {

		node = node->llink;
	}

	return node;
}

template <class T>
void BST<T>::inOrder() {

	helperInOrder(m_root);
}

template <class T>
void BST<T>::helperInOrder(Node *ptr) {

	if (ptr != nullptr) {

		helperInOrder(ptr->llink);
		std::cout << ptr->data << ' ';
		helperInOrder(ptr->rlink);
	}
}

template <class T>
void BST<T>::preOrder() {

	helperPreOrder(m_root);
}

template<class T>
void BST<T>::helperPreOrder(Node *node) {

	if (node != nullptr) {

		std::cout << node->data << ' ';
		helperPreOrder(node->llink);
		helperPreOrder(node->rlink);

	}
}

template <class T>
void BST<T>::postOrder() {

	helperPostOrder(m_root);
}

template<class T>
void BST<T>::helperPostOrder(Node* node) {

	if (node != nullptr) {

		helperPostOrder(node->llink);
		helperPostOrder(node->rlink);
		std::cout << node->data << ' ';
	}
}

#endif /* BSTh_hpp */
