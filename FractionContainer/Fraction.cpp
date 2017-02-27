// Filename: Fraction.cpp
// Additional Files: Fraction.hpp, FractionSource.cpp
// Created by Christian Broms on 2/20/17
// Compiler: MS Visual Studio 2015

#include "Fraction.hpp"
#include <iostream>
#include <sstream>
#include <string>

Fraction::Fraction() {

	m_num = 1;
	m_denom = 1;
}

Fraction::Fraction(const int& p_num, const int& p_denom) {

	m_num = p_num;
	m_denom = p_denom;
}

// augmented assignments
void Fraction:: operator += (Fraction& rhs) {

	if (this->m_denom == rhs.m_denom) {

		this->m_num = rhs.m_num + this->m_num;
	}
	else {

		Fraction temp;
		temp.m_denom = this->m_denom;
		temp.m_num = this->m_num;
		this->m_denom *= rhs.m_denom;
		this->m_num *= rhs.m_denom;
		rhs.m_denom *= temp.m_denom;
		rhs.m_num *= temp.m_denom;

		this->m_num = rhs.m_num + this->m_num;
	}
}

void Fraction:: operator-=(Fraction &rhs) {

	if (this->m_denom == rhs.m_denom) {

		this->m_num = this->m_num - rhs.m_num;
	}
	else {

		Fraction temp;
		temp.m_denom = this->m_denom;
		temp.m_num = this->m_num;
		this->m_denom *= rhs.m_denom;
		this->m_num *= rhs.m_denom;
		rhs.m_denom *= temp.m_denom;
		rhs.m_num *= temp.m_denom;

		this->m_num = this->m_num - rhs.m_num;
	}
}

void Fraction:: operator*=(Fraction &rhs) {

	this->m_num = this->m_num * rhs.m_num;
	this->m_denom = this->m_denom * rhs.m_denom;
}

void Fraction:: operator/=(Fraction &rhs) {

	this->m_num = this->m_num += rhs.m_denom;
	this->m_denom = this->m_denom *= rhs.m_num;
}

Fraction Fraction::operator++() {

	++(this->m_num);
	return *this;
}

Fraction Fraction::operator++(int p_dummy) {

	Fraction temp;
	temp.m_denom = this->m_denom;
	temp.m_num = this->m_num;
	this->m_num += 1;
	return temp;
}

Fraction Fraction::operator--() {
	--(this->m_num);
	return *this;
}

Fraction Fraction::operator--(int p_dummy) {

	Fraction temp;
	temp.m_denom = this->m_denom;
	temp.m_num = this->m_num;
	this->m_num -= 1;
	return temp;
}

//// streams
//std::ostream& operator<<(std::ostream& out, const Fraction& printMe) {
//
//	out << printMe.m_intNum;
//	return out;
//}

std::istream& operator >> (std::istream& in, Fraction& readMe) {

	std::string str = "";
	char plusSign = ' ';
	char forwardSlash = ' ';

	in >> str;

	std::stringstream ss(str);

	int wholeNum = 0;
	int numerator = 0;
	int denominator = 1;

	ss >> wholeNum; 

	if (!ss.eof()) {

		if (ss.peek() == '/') { 

			numerator = wholeNum;
			wholeNum = 0;
			ss >> forwardSlash;
			ss >> denominator;
		}
		else if (ss.peek() == '+'){ 

			ss >> plusSign;
			ss >> numerator;
			ss >> forwardSlash;
			ss >> denominator;
		}
	}

	numerator = numerator + wholeNum * denominator;

	readMe.m_num = numerator;
	readMe.m_denom = denominator;

	return in;
}

//// comparison operators
//bool operator<(const Fraction& lhs, const Fraction& rhs) {
//	return lhs.m_intNum < rhs.m_intNum ? true : false;
//}
//
//bool operator<=(const Fraction& lhs, const Fraction& rhs) {
//	return lhs.m_intNum <= rhs.m_intNum ? true : false;
//}
//
//bool operator==(const Fraction& lhs, const Fraction& rhs) {
//	return lhs.m_intNum == rhs.m_intNum ? true : false;
//}
//
//bool operator>(const Fraction& lhs, const Fraction& rhs) {
//	return lhs.m_intNum > rhs.m_intNum ? true : false;
//}
//
//bool operator>=(const Fraction& lhs, const Fraction& rhs) {
//	return lhs.m_intNum >= rhs.m_intNum ? true : false;
//}
//
//bool operator!=(const Fraction& lhs, const Fraction& rhs) {
//	return lhs.m_intNum != rhs.m_intNum ? true : false;
//}
//
//
//// arithmetic operators
//Fraction operator+(const Fraction &lhs, const Fraction& rhs) {
//	IntItem temp = lhs.m_intNum + rhs.m_intNum;
//	return temp;
//}
//
//Fraction operator-(const Fraction &lhs, const Fraction& rhs) {
//	IntItem temp = lhs.m_intNum - rhs.m_intNum;
//	return temp;
//}
//
//Fraction operator*(const Fraction &lhs, const Fraction& rhs) {
//	IntItem temp = lhs.m_intNum * rhs.m_intNum;
//	return temp;
//}
//
//Fraction operator/(const Fraction &lhs, const Fraction& rhs) {
//	IntItem temp = lhs.m_intNum / rhs.m_intNum;
//	return temp;
//}
