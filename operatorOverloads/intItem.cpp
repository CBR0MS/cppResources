#include "intItemH.h"
#include <iostream>

using namespace std;

IntItem::IntItem(int p_num1)
{
	this->m_intNum = p_num1;
}

// augmented assignments
void IntItem:: operator+= (const IntItem& rhs) {

	this->m_intNum = rhs.m_intNum + this->m_intNum;
}

void IntItem:: operator-=(const IntItem &right) {

	this->m_intNum = this->m_intNum - right.m_intNum;
}
void IntItem:: operator*=(const IntItem &right) {

	this->m_intNum = this->m_intNum * right.m_intNum;	
}

void IntItem:: operator/=(const IntItem &right){

	this->m_intNum = this->m_intNum / right.m_intNum;
}

IntItem IntItem::operator++() 
{
	++(this->m_intNum);
	return *this;
}

IntItem IntItem::operator++(int p_dummy)
{
	IntItem temp;
	temp.m_intNum = this->m_intNum;
	this->m_intNum += 1;
	return temp;
}

IntItem IntItem::operator--() {
	--(this->m_intNum);
	return *this;
}

IntItem IntItem::operator--(int p_dummy) {
	IntItem temp;
	temp.m_intNum = this->m_intNum;
	this->m_intNum -= 1;
	return temp;
}

// streams
std::ostream& operator<<(std::ostream& out, const IntItem& printMe)
{
	out << printMe.m_intNum;
	return out;
}

std::istream& operator >> (std::istream& in, IntItem& readMe)
{
	in >> readMe.m_intNum;
	return in;

}

// comparison operators
bool operator<(const IntItem& lhs, const IntItem& rhs) {
	return lhs.m_intNum < rhs.m_intNum ? true : false;
}

bool operator<=(const IntItem& lhs, const IntItem& rhs) {
	return lhs.m_intNum <= rhs.m_intNum ? true : false;
}

bool operator==(const IntItem& lhs, const IntItem& rhs) {
	return lhs.m_intNum == rhs.m_intNum ? true : false;
}

bool operator>(const IntItem& lhs, const IntItem& rhs) {
	return lhs.m_intNum > rhs.m_intNum ? true : false;
}

bool operator>=(const IntItem& lhs, const IntItem& rhs) {
	return lhs.m_intNum >= rhs.m_intNum ? true : false;
}

bool operator!=(const IntItem& lhs, const IntItem& rhs) {
	return lhs.m_intNum != rhs.m_intNum ? true : false;
}

　
// arithmetic operators
IntItem operator+(const IntItem &lhs, const IntItem& rhs){
	IntItem temp = lhs.m_intNum + rhs.m_intNum;
	return temp;
}

IntItem operator-(const IntItem &lhs, const IntItem& rhs){
	IntItem temp = lhs.m_intNum - rhs.m_intNum;
	return temp;
}

IntItem operator*(const IntItem &lhs, const IntItem& rhs){
	IntItem temp = lhs.m_intNum * rhs.m_intNum;
	return temp;
}

IntItem operator/(const IntItem &lhs, const IntItem& rhs){
	IntItem temp = lhs.m_intNum / rhs.m_intNum;
	return temp;
}　
