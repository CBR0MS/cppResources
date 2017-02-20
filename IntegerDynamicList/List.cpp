// Filename: List.cpp
// Additional Files: List.hpp, ListSource.cpp
// Created by Christian Broms on 2/16/17
// Compiler: MS Visual Studio 2015

#include "List.hpp"
#include <iostream>

List::List() {

	dataList = new int[10];
	length = 0;
	capacity = 10;
}

List::List(int p_cap) {

	dataList = new int[p_cap];
	length = 0;
	capacity = p_cap;
}

List::List(const List& p_list) {

	//Allocate separate memory
	dataList = new int[p_list.capacity];

	//Copy over attriutes of p_obj 
	capacity = p_list.capacity;
	length = p_list.length;

	for (int i = 0; i < p_list.capacity; i++) {
		dataList[i] = p_list.dataList[i];
	}
}

void List::addItem(int newItem) {

	if (length != capacity) {

		dataList[length] = newItem;
		length++;
	}
}

void List::printList() {

	for (int i = 0; i < length; i++)
		std::cout << dataList[i] << ' ';
}
void List::decrementAll() {

	for (int i = 0; i < length; i++)
		dataList[i]--;
}

List& List::operator= (const List& p_list) {

	//Allocate separate memory
	dataList = new int[p_list.capacity];

	//Copy over attriutes of p_obj 
	capacity = p_list.capacity;
	length = p_list.length;

	for (int i = 0; i < p_list.capacity; i++) {
		dataList[i] = p_list.dataList[i];
	}

	return *this;
}

List::~List() {

	// object deconstructor
}
