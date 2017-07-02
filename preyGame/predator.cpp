//  File: Predator.cpp
//  Created by Christian Broms on 4/7/17.

#include <iostream>
#include <vector>
#include <algorithm>
#include "Predator.hpp"
#include "Organism.hpp"

Predator::Predator(int rowLoc, int colLoc)
	: Organism(rowLoc, colLoc)
{
	symb = 'X'; 
}

void Predator::move(Organism* arr[20][20]) {

	/*
	 PREDATOR RULES: IF there is prey in an dajacent cell, eat the prey,
	 otherwise, move according to the same rules as the prey
	 If it survives eight steps, it spawns a new child in the same manner as the prey
	 If it does not eat in three moves, it will die and be removed
*/

	if (arr[i][j]->hunger == 3) {
		arr[i][j] = new Organism(i, j);
	}
	else {

		if (arr[i][j]->moves == 8) {
			reproduce(arr);
			arr[i][j]->moves = 0;
		}
		else {

			bool done = false;

			if (j + 1 < 20) { // checking the right 

				if (arr[i][j + 1]->symb == 'O') {
					arr[i][j + 1] = new Predator(i, j + 1);
					arr[i][j + 1]->moves = arr[i][j]->moves++;
					arr[i][j] = new Organism(i, j);
					done = true;
				}
			}
			else if (j - 1 >= 0 && !done) { // checking the left

				if (arr[i][j - 1]->symb == 'O') {
					arr[i][j - 1] = new Predator(i, j - 1);
					arr[i][j - 1]->moves = arr[i][j]->moves++;
					arr[i][j] = new Organism(i, j);
					done = true;
				}
			}
			else if (i + 1 < 20 && !done) { // checking the bottom

				if (arr[i + 1][j]->symb == 'O') {
					arr[i + 1][j] = new Predator(i + 1, j);
					arr[i + 1][j]->moves = arr[i][j]->moves++;
					arr[i][j] = new Organism(i, j);

					done = true;
				}
			}
			else if (i - 1 >= 0 && !done) { // checking the top

				if (arr[i - 1][j]->symb == 'O') {
					arr[i - 1][j] = new Predator(i - 1, j);
					arr[i - 1][j]->moves = arr[i][j]->moves++;
					arr[i][j] = new Organism(i, j);
					done = true;
				}
			}

			if (!done) { // no prey to eat, so we'll randomly move it

				bool place = true;
				int iterations = 0;
				std::vector<int> randomNums = { 1, 2, 3, 4 };
				std::random_shuffle(randomNums.begin(), randomNums.end());

				for (int k = 0; k < 4; k++) {

					if (place) {

						switch (randomNums.at(k)) {
						case 1: // move right
							if (j + 1 < 20) {
								if (arr[i][j + 1]->symb != 'X') {
									arr[i][j + 1] = new Predator(i, j + 1);
									arr[i][j + 1]->hunger = arr[i][j]->hunger++;
									arr[i][j + 1]->moves = arr[i][j]->moves++;
									arr[i][j] = new Organism(i, j);
									place = false;
								}
							}
							break;
						case 2: // move left 
							if (j - 1 >= 0) {
								if (arr[i][j - 1]->symb != 'X') {
									arr[i][j - 1] = new Predator(i, j - 1);
									arr[i][j - 1]->hunger = arr[i][j]->hunger++;
									arr[i][j - 1]->moves = arr[i][j]->moves++;
									arr[i][j] = new Organism(i, j);

									place = false;
								}
							}
							break;
						case 3: // move bottom
							if (i + 1 < 20) {
								if (arr[i + 1][j]->symb != 'X') {
									arr[i + 1][j] = new Predator(i + 1, j);
									arr[i + 1][j]->hunger = arr[i][j]->hunger++;
									arr[i + 1][j]->moves = arr[i][j]->moves++;
									arr[i][j] = new Organism(i, j);
									place = false;
								}
							}
							break;
						case 4: // move top
							if (i - 1 >= 0) {
								if (arr[i - 1][j]->symb != 'X') {
									arr[i - 1][j] = new Predator(i - 1, j);
									arr[i - 1][j]->hunger = arr[i][j]->hunger++;
									arr[i - 1][j]->moves = arr[i][j]->moves++;
									arr[i][j] = new Organism(i, j);
									place = false;
								}
							}
							break;
						}
					}
				}
			}
		}
	}
}
void Predator::reproduce(Organism* arr[20][20]) {

	bool done = false;

	if (j + 1 < 20) { // checking the right 

		if (arr[i][j + 1]->symb == ' ') {
			arr[i][j + 1] = new Predator(i, j + 1);
			done = true;
		}
	}
	else if (j - 1 >= 0 && !done) { // checking the left

		if (arr[i][j - 1]->symb == ' ') {
			arr[i][j - 1] = new Predator(i, j - 1);
			done = true;
		}
	}
	else if (i + 1 < 20 && !done) { // checking the bottom

		if (arr[i + 1][j]->symb == ' ') {
			arr[i + 1][j] = new Predator(i + 1, j);
			done = true;
		}
	}
	else if (i - 1 >= 0 && !done) { // checking the top

		if (arr[i - 1][j]->symb == ' ') {
			arr[i - 1][j] = new Predator(i - 1, j);
			done = true;
		}
	}
 }

std::ostream& operator<<(std::ostream& out, const Predator& print) {

	out << print.symb;
	return out;
}
