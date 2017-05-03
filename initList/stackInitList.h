#ifndef MYSTACK_H
#define MYSTACK_H

#include <initializer_list>
#include <iostream>

using namespace std;

template<class T>
class MyStack {

public:
	MyStack() { };
	MyStack(initializer_list<T> initlist);
	void push(T p_newItem);
	void pop();
	T top();

private:

	int capacity = 5;
	T *m_arr = new T[capacity];
	int size = 0;
	void addCapacity();
};

template<class T>
MyStack<T>::MyStack(initializer_list<T> initlist) {

	size = initlist.size();

	if (size > capacity) {

		while (capacity < size) {
			addCapacity();
		}
	}

	for (int i = 0; i < initlist.size(); i++) {

		m_arr[i] = *(initlist.begin() + i);
	}
}

template<class T> 
void MyStack<T>::addCapacity() {

	capacity *= 2;

	T *temp = new T[capacity];

	for (int i = 0; i < capacity; i++) {

		if (i <= size) {

			temp[i] = m_arr[i];
		}
		else {
			temp[i] = T();
		}
	}
	m_arr = temp;
}

template<class T> 
void MyStack<T>::push(T p_newItem) {

	size++;
	if (size > capacity) {
		addCapacity();
	}
	m_arr[size] = p_newItem;
}

template<class T>
T  MyStack<T>::top() {

	return m_arr[size];
}

template <class T>
void MyStack<T>::pop() {

	m_arr[size] = T();
	size--;
}

#endif // MYSTACK_H
