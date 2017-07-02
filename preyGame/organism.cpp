
//  File: Organism.cpp
//  Created by Christian Broms on 4/7/17.

#include <iostream>
#include "Organism.hpp"

Organism::Organism(int rowLoc, int colLoc)
    : i(rowLoc), j(colLoc)
{} 

void Organism::move(Organism* arr[20][20]) { } // defined in inherited classes

void Organism::reproduce(Organism* arr[20][20]) { } // defined in inherited classes

std::ostream& operator<<(std::ostream& out, const Organism& print) {

	out << print.symb;
	return out;
}
