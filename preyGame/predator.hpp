//  File: Predator.hpp
//  Created by Christian Broms on 4/7/17.

#ifndef Predator_hpp
#define Predator_hpp
#include "Organism.hpp"
#include <iostream>

class Predator : public Organism {
    
public:
    
    Predator(int rowLoc, int colLoc);
    void move(Organism* arr[20][20]);
	void reproduce(Organism* arr[20][20]);
	friend std::ostream& operator<<(std::ostream& out, const Predator& print);

};

#endif /* Predator_hpp */
