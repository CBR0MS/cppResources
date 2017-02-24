// File: linkedListVector.hpp
// Compiler: MS Visual Studio 2015
// Created by Christian Broms on 2/23/17

#include <iostream>
#include <limits>

template<typename T>
class List {

public:

	List();

	/*** getters ***/
	int size();
	void displayList();

	/*** setter ***/
	void push_front(T p_newValue);
	void push_back(T p_newValue);
	void pop_front();
	void pop_back();
	void erase(T p_eraseItem);

private:

	struct Node {

		T data;
		Node* llink;
		Node* rlink;
	};

	Node* hPtr = nullptr;
	Node* tPtr = nullptr;
	Node* mPtr = nullptr;
	Node* temp = nullptr;
	int m_size = 0;
};

template<typename T>
List<T>::List() {

	hPtr = new Node;
	tPtr = new Node;
	hPtr->llink = nullptr;
	hPtr->data = std::numeric_limits<T>::min();
	hPtr->rlink = tPtr;
	tPtr->llink = hPtr;
	tPtr->data = std::numeric_limits<T>::max();
	tPtr->rlink = nullptr;
}

template<typename T>
int List<T>::size() {
	return size;
}

template<typename T>
void List<T>::displayList() {

	mPtr = hPtr;
	while (mPtr != nullptr) {

		if (mPtr->data != std::numeric_limits<T>::max() && mPtr->data != std::numeric_limits<T>::min()) {

			std::cout << mPtr->data << ' ';
		}
		mPtr = mPtr->rlink;
	}
}

template<typename T>
void List<T>::push_front(T p_newValue) {

	m_size++;

	mPtr = hPtr;
	temp = new Node;
	temp->data = p_newValue;

	temp->llink = mPtr;
	temp->rlink = mPtr->rlink;
	mPtr->rlink->llink = temp;
	mPtr->rlink = temp;
}

template<typename T>
void List<T>::push_back(T p_newValue) {

	m_size++;

	mPtr = hPtr;
	temp = new Node;
	temp->data = p_newValue;

	for (int i = 0; i < m_size - 1; i++) {
		mPtr = mPtr->rlink;
	}
	temp->llink = mPtr;
	temp->rlink = mPtr->rlink;
	mPtr->rlink->llink = temp;
	mPtr->rlink = temp;
}

template<typename T>
void List<T>::pop_front() {

	mPtr = hPtr->rlink;
	mPtr->llink->rlink = mPtr->rlink;
	mPtr->rlink->llink = mPtr->llink;
	m_size--;
}

template<typename T>
void List<T>::pop_back() {
	
	mPtr = hPtr;

	for (int i = 0; i < m_size; i++) {
		mPtr = mPtr->rlink;
	}
	mPtr->llink->rlink = mPtr->rlink;
	mPtr->rlink->llink = mPtr->llink;
	m_size--;
}

template<typename T>
void List<T>::erase(T p_eraseItem) {

	mPtr = hPtr;

	for (int i = 0; i < m_size + 1; i++) {

		if (mPtr->data == p_eraseItem) {

			mPtr->llink->rlink = mPtr->rlink;
			mPtr->rlink->llink = mPtr->llink;
			m_size--;
		}
		mPtr = mPtr->rlink;
	}
}
