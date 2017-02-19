// Filename: IntItem.hpp
// Additional Files: IntItem.cpp, IntItemSource.cpp
// Created by Christian Broms on 2/16/17
// Compiler: MS Visual Studio 2015

#ifndef IntItem_hpp
#define IntItem_hpp

#include <iostream>

class IntItem
{
public:

	IntItem(int p_num = 1);

	// augmented assignments
	void operator+=(const IntItem& rhs);
	void operator-=(const IntItem &right);
	void operator*=(const IntItem &right);
	void operator/=(const IntItem &right);
	IntItem operator++();
	IntItem operator++(int p_dummy);
	IntItem operator--();
	IntItem operator--(int p_dummy);

	// streams
	friend std::ostream& operator<<(std::ostream& out, const IntItem& printMe);
	friend std::istream& operator >> (std::istream& in, IntItem& readMe);

	// comparison operators
	friend bool operator<(const IntItem& lhs, const IntItem& rhs);
	friend bool operator<=(const IntItem& lhs, const IntItem& rhs);
	friend bool operator==(const IntItem& lhs, const IntItem& rhs);
	friend bool operator>(const IntItem& lhs, const IntItem& rhs);
	friend bool operator>=(const IntItem& lhs, const IntItem& rhs);
	friend bool operator!=(const IntItem& lhs, const IntItem& rhs);

	// arithmetic operators
	friend IntItem operator+(const IntItem &lhs, const IntItem& rhs);
	friend IntItem operator-(const IntItem &lhs, const IntItem& rhs);
	friend IntItem operator*(const IntItem &lhs, const IntItem& rhs);
	friend IntItem operator/(const IntItem &lhs, const IntItem& rhs);

private:

	int m_intNum;
};

#endif /* IntItem_hpp */
