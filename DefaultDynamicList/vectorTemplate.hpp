//  File: List.hpp
//  Additonal Files: main.cpp
//  Compiler: MS Visual Studio 2017
//  Created by Christian Broms on 2/14/17.
//  class is designed to mimic a Vector container

#ifndef List_hpp
#define List_hpp

template<class T>
class List {

public:

	typedef T value_type;

	/* CONSTRUCTORS */

	List(); 
	List(int p_capacity); 
	List(T p_value, int p_capacity);

	/* GETTERS */ 

	int getSize();
	int getCapacity();
	void displayList();

	/* SETTERS */

	void setValue(T p_newValue);
	void push_back(T p_value);
	void pop_back();

private:

	void increaseCapacity(int addCapacity);
	T* m_arr = NULL;
	int m_capacity;
	int m_size;

};

template<class T>
List<T>::List() {

	m_arr = new T[0];
	m_size = 0;
	m_capacity = 0;
}

template<class T>
List<T>::List(int p_capacity) {

	m_arr = new T[p_capacity];
	m_size = p_capacity;
	m_capacity = p_capacity;

	for (int i = 0; i < m_size; i++) {
		m_arr[i] = value_type();
	}

}

template<class T>
List<T>::List(T p_value, int p_capacity) {

	m_arr = new T[p_capacity];
	m_size = p_capacity;
	m_capacity = p_capacity;

	for (int i = 0; i < m_size; i++) {
		m_arr[i] = p_value;
	}
}

template<class T>
int List<T>::getSize() {
	return m_size;
}

template<class T>
int List<T>::getCapacity() {
	return m_capacity;
}

template<class T>
void List<T>::displayList() {

	for (int i = 0; i < m_size; i++) {
		std::cout << m_arr[i] << ' ';
	}
}

template<class T>
void List<T>::setValue(T p_newValue) {

	if (m_size >= m_capacity) {
		std::cout << "ERROR! Overflow, increasing capacity by 2\n";
		increaseCapacity(2);
		m_arr[m_size] = p_newValue;
		m_size++;
	}
	else {
		m_arr[m_size] = p_newValue;
		m_size++;
	}
}

template<class T>
void  List<T>::push_back(T p_value) {

	if (m_size + 1>= m_capacity) {
		increaseCapacity(1);
		m_arr[m_size] = p_value;
		m_size++;
	}
	else {
		m_arr[m_size] = p_value;
		m_size++;
	}
}

template<class T>
void  List<T>::pop_back() {

	m_arr[m_size - 1] = value_type();
	m_size--;
}

template<class T>
void List<T>::increaseCapacity(int addCapacity) {

	// make a temporary array
	T* tempArr = new T[m_capacity];

	// copy values to temp
	for (int i = 0; i < m_size; i++) {
		tempArr[i] = m_arr[i];
	}

	// declare new array and deallocate old one
	delete[] m_arr;
	m_arr = NULL;
	m_capacity += addCapacity;
	m_arr = new T[m_capacity];

	// copy temp values to new array
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = tempArr[i];
	}

	// deallocation of temporary array
	delete[] tempArr;
	tempArr = NULL;
}

#endif /* List_hpp */

/* 
CONSTRUCTORS:
List();
	creates a list with size 0
List(int p_capacity);
	creates a list with capacity as passed through constructor
	list is initalized with default values of type T
List(T p_value, int p_capacity);
	creates a list with capacity as passed through constructor
	list is initalized with values of type T passed through constructor

GETTERS:
int getSize();
	 returns the number of elements in the list
int getCapacity();
	 reutrns the capacity of the list
void displayList();
	displays the list

SETTERS:
void setValue(T p_newValue);
	sets the entire list with value of type T
void push_back(T p_value);
	adds passed value of type T to the back of the list
void pop_back();
	removes the last element of the list 
*/
