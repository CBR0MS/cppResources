#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {

	ofstream ofile;
	ofile.open("vegetables.txt");
	string path = "C:\\Users\\Student\\Documents\\Visual Studio 2015\\Projects\\ConsoleApplication1\\ConsoleApplication1\\vegetables.txt";
	ofile << "asparagus#$23.34\n";
	ofile.close();

	fstream ffile(path, ios::in | ios::out);
	string tempStr = "";
	ffile.seekp(0, ios::end);
	int size = ffile.tellp();

	for (int i = 0; i < size; i++) {

		ffile.seekp(i, ios::beg);
		char temp = ' ';
		ffile.get(temp);
		tempStr += temp;
	}

	stringstream ss;
	ss.str(tempStr);

	string veg = "";
	char sign = ' ';
	string price = "";
	getline(ss, veg, '#');
	ss.get(sign);
	ss >> price;

	cout << veg << endl;
	cout << sign << endl; 
	cout << price << endl;

	ffile.seekp(0, ios::end);
	ffile << "\nblack truffles#$230.99\nangus beef#$88.23";

	return 0;
}

