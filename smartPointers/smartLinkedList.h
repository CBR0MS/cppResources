#pragma once
#include <iostream>
#include <limits>
#include <memory>

using namespace std;

template<typename T>
class List {

public:

	List();

	/*** getters ***/
	int size();
	void displayList();

	/*** setters ***/
	void push_back(T p_newValue);
	void pop_back();

private:

	struct Node {

		T data;
		shared_ptr<Node> link;
	};

	shared_ptr<Node> hPtr;
	shared_ptr<Node> tPtr;
	shared_ptr<Node> mPtr;
	shared_ptr<Node> temp;

	int m_size = 0;
};

template<typename T>
List<T>::List() {

	hPtr = make_shared<Node>();
	tPtr = make_shared<Node>();
	hPtr->data = numeric_limits<T>::min();
	hPtr->link = tPtr;
	tPtr->data = numeric_limits<T>::max();
	tPtr->link = nullptr;
}

template<typename T>
int List<T>::size() {
	return size;
}

template<typename T>
void List<T>::displayList() {

	mPtr = hPtr;
	while (mPtr != nullptr) {

		if (mPtr->data != numeric_limits<T>::max() && mPtr->data != numeric_limits<T>::min()) {

			cout << mPtr->data << ' ';
		}
		mPtr = mPtr->link;
	}
}


template<typename T>
void List<T>::push_back(T p_newValue) {

	m_size++;
	mPtr = hPtr;
	temp = make_shared<Node>();
	temp->data = p_newValue;

	for (int i = 0; i < m_size - 1; i++) {
		mPtr = mPtr->link;
	}
	temp->link = mPtr->link;
	mPtr->link = temp;
}

template<typename T>
void List<T>::pop_back() {

	mPtr = hPtr;

	for (int i = 0; i < m_size - 1; i++) {
		mPtr = mPtr->link;
	}

	mPtr->link = nullptr;

	m_size--;
}
