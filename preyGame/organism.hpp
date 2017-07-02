
// File: Organism.hpp
//  Created by Christian Broms on 4/7/17.

#ifndef Organism_hpp
#define Organism_hpp
#include <iostream>

class Organism {
    
public:
    
    Organism(int rowLoc, int colLoc);
    virtual void move(Organism* arr[20][20]);
	virtual void reproduce(Organism* arr[20][20]);
	friend std::ostream& operator<<(std::ostream& out, const Organism& print);

	char symb = ' '; // how the organism will be displayed
	int hunger = 0;  // keeping track of how long it has been without eating
	int moves = 0;	 // how many moves has it made
    
protected:

    int i; // row location
    int j; // column location
};

#endif /* Organism_hpp */
