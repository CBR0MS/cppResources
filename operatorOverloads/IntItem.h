#ifndef IntItemClass
#define IntItemClass

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

#endif /* IntItemClass */
