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

	/***** CONSTRUCTORS & DESTRUCTOR *****/

	Fraction();
	Fraction(int p_num);
	Fraction(const int& p_num, const int& p_denom);
	~Fraction();

	/***** AUGMENTED ASSIGNMENTS *****/

	void operator+=(Fraction& rhs);
	void operator-=(Fraction& rhs);
	void operator*=(Fraction& rhs);
	void operator/=(Fraction& rhs);
	void operator+=(int rhs);
	void operator-=(int rhs);
	void operator*=(int rhs);
	void operator/=(int rhs);
	Fraction operator++();
	Fraction operator++(int p_dummy);
	Fraction operator--();
	Fraction operator--(int p_dummy);

	/***** STREAMS *****/

	friend std::ostream& operator<<(std::ostream& out, const Fraction& print);
	friend std::istream& operator>>(std::istream& in, Fraction& read);

	/***** COMPARISON OPERATORS *****/

	friend bool operator<(const Fraction& lhs, const Fraction& rhs);
	friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator==(const Fraction& lhs, const Fraction& rhs);
	friend bool operator>(const Fraction& lhs, const Fraction& rhs);
	friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
	friend bool operator!=(const Fraction& lhs, const Fraction& rhs);

	/***** ARITHMETIC OPERATORS *****/

	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

private:

	int gcd(const int& m, const int& n);
	int m_num;
	int m_denom;
	
};

#endif /* Fraction_hpp */
