//  File: Driver.cpp
//  Created by Christian Broms on 4/7/17.
//  Demonstration of plymorphic behavior using a simulation

#include "Organism.hpp"
#include "Prey.hpp"
#include "Predator.hpp"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Organism* oArr[20][20];	
bool first = true;

bool simulation() {
	
	if (first) {

		srand(time(0));

		// seeding the array with random prey and predators
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {

				int random = 1 + rand() % (7 - 1 + 1);

				switch (random) {

				case 1:
					oArr[i][j] = new Predator(i, j);
					break;
				case 2:
					oArr[i][j] = new Prey(i, j);
					break;
				default:
					oArr[i][j] = new Organism(i, j);
					break;
				}
				cout << *oArr[i][j] << ' ';
			}
			cout << endl;
		}
		first = false;
	}
	else {
		// logic
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				oArr[i][j]->move(oArr);
			}
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				cout << *oArr[i][j] << ' ';
			}
			cout << endl;
		}
	}

	// allow simulation to re-run
	string input;
	cout << "enter 1 to continue...  ";
	cin >> input;

	if (input == "1") {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	// run the simulation
	bool res;

	do {
		res = simulation();

	} while (res);

	return 0;
}
