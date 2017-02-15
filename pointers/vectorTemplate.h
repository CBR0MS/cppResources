// class is designed to model a vector
// with functions such as push_back and pop_back

#include <iostream>

template<class T>
class List {

public:

	typedef T value_type;

	// constructors
	List(int p_capacity);
	List(T p_value, int p_capacity);

	// getters
	int getSize();
	int getCapacity();
	void displayList();

	// setters
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

	if (m_size + 1 >= m_capacity) {
		increaseCapacity(1);
		m_arr[m_size] = p_value;
	}
	else {
		m_arr[m_size] = p_value;
	}
}

template<class T>
void  List<T>::pop_back() {

	m_arr[m_size] = value_type();
	size--;
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
