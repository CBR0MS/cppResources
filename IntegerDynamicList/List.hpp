// Filename: List.hpp
// Additional Files: List.cpp, ListSource.cpp
// Created by Christian Broms on 2/16/17
// Compiler: MS Visual Studio 2015

#ifndef List_hpp
#define List_hpp

class List
{
public:
	List();
	List(int);
	List(const List&);

	void addItem(int newItem);
	void printList();
	void decrementAll();

	List& operator= (const List&);
	~List();

private:
	int *dataList;
	int length;
	int capacity;
};

#endif /* List_hpp */
