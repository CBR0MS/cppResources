// File: VectorLab.cpp
// Created by Christian Broms on 4/11/17.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	vector<char> charVec;
	vector<char> alph;
	charVec.reserve(100);
	alph.reserve(100);

	// making a complete vector of letters
	for (char i = 'A'; i <= 'Z'; i++) {
		alph.push_back(i);
	}
	random_shuffle(alph.begin(), alph.end());

	// adding random letters from the complete vector into the incomplete vector (only 20 of them)
	for (int i = 0; i < 20; i++) {
		charVec.push_back(alph.at(i));
	}

	// sorting the incomplete vector
	sort(charVec.begin(), charVec.end());

	// sorting the complete vector
	sort(alph.begin(), alph.end());

	vector<char>::iterator iter;
	bool res = true;	
	bool again = true;  

	// comparing the vectors and adding missing letters to the incomplete one from the complete one
	while (res) {

		iter = charVec.begin();

		for (char i = 'A'; i <= 'Z'; i++) {

			if (*iter != i) {

				iter = charVec.insert(iter, i);
				again = true;
				break;
			}
			else {
				again = false;
			}
			iter++;
		}
		if (!again) {
			res = false;
		}
	}
	charVec.shrink_to_fit();

	// display
	for (char item : charVec) {
		cout << item << ' ';
	}
	return 0;
}
