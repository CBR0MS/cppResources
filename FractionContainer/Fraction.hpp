// Filename: Fraction.hpp
// Additional Files: Fraction.cpp, FractionSource.cpp
// Created by Christian Broms on 2/20/17
// Compiler: MS Visual Studio 2015

#include <iostream>

#ifndef Fraction_hpp
#define Fraction_hpp

class Fraction
{
public:

	Fraction();
	Fraction(const int& p_num, const int& p_denom);

	// augmented assignments
	void operator+=(Fraction& rhs);
	void operator-=(Fraction& rhs);
	void operator*=(Fraction& rhs);
	void operator/=(Fraction& rhs);
	Fraction operator++();
	Fraction operator++(int p_dummy);
	Fraction operator--();
	Fraction operator--(int p_dummy);

	// streams
	/*friend std::ostream& operator<<(std::ostream& out, const Fraction& printMe);*/
	friend std::istream& operator >> (std::istream& in, Fraction& readMe);

	//// comparison operators
	//friend bool operator<(const Fraction& lhs, const Fraction& rhs);
	//friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
	//friend bool operator==(const Fraction& lhs, const Fraction& rhs);
	//friend bool operator>(const Fraction& lhs, const Fraction& rhs);
	//friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
	//friend bool operator!=(const Fraction& lhs, const Fraction& rhs);

	//// arithmetic operators
	//friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	//friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	//friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	//friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

private:

	int m_num;
	int m_denom;
	
};

#endif /* Fraction_hpp */
