//  File: Prey.hpp
//  Created by Christian Broms on 4/7/17.

#ifndef Prey_hpp
#define Prey_hpp
#include "Organism.hpp"
#include <iostream>

class Prey : public Organism {

public:

	Prey(int rowLoc, int colLoc);
	void move(Organism* arr[20][20]);
	void reproduce(Organism* arr[20][20]);
	friend std::ostream& operator<<(std::ostream& out, const Prey& print);

};

#endif /* Prey_hpp */
