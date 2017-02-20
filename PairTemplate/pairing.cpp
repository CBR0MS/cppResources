#ifndef Pair_hpp
#define Pair_hpp

#include <iostream>

template <class T1, class T2>
class Pair {

public:
	typedef T1 value_typeT1;
	typedef T2 value_typeT2;
	Pair();
	Pair(T1 p_first, T2 p_second);

	// getters
	T1 first();
	T2 second();

	// setter
	void setValuesToPair(T1 p_first, T2 p_second);

private:

	T1 m_first;
	T2 m_second;
};

template <class T1, class T2>
Pair<T1, T2>::Pair()
	: m_first(value_typeT1()), m_second(value_typeT2())
{}

template <class T1, class T2>
Pair<T1, T2>::Pair(T1 p_first, T2 p_second)
	: m_first(p_first), m_second(p_second)
{}

template <class T1, class T2>
void Pair<T1, T2>::setValuesToPair(T1 p_first, T2 p_second) {
	m_first = p_first;
	m_second = p_second;
}

template <class T1, class T2>
T1 Pair<T1, T2>::first() {
	return m_first;
}

template <class T1, class T2>
T2 Pair<T1, T2>::second() {
	return m_second;
}

#endif /* Pair_hpp */
