// File: TextEdit.cpp
// Created by Christian Broms on 2/27/17
// Compiler: MS Visual Studio 2015

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {

	ifstream file("C:\\Users\\Student\\Documents\\life.txt");

	if (file.is_open()) {

		char sentence[100];
		char inChar = ' ';
		int charNumber = 0;
		bool isSpace = false;

		while (!file.eof()) {

			// read characters one by one
			file.get(inChar);

			// if first is lowercase, capitalize it
			if (charNumber == 0) {

				if (islower(inChar)) {

					inChar = toupper(inChar);
				}
			}
			else {
				// if any others are uppercase, lowercase it
				if (isupper(inChar)) {

					inChar = tolower(inChar);
				}
			}


			if (isspace(inChar)) {

				// this character is a space, check if the next is too
				char temp = file.peek();

				while (isspace(temp)) {

					file.ignore();
					temp = file.peek();
				}
			}
		
			sentence[charNumber] = inChar;
			charNumber++;
		}

		file.close();

		ofstream out("C:\\Users\\Student\\Documents\\lifeEdited.txt");

		for (int i = 0; i < charNumber - 1; i++) {

			out << sentence[i];
		}

		out.close();
	}
	return 0;
}
