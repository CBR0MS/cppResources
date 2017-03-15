#include <iostream>
#include <sstream>

using namespace std;

int main() {

	stringstream mySS;
	mySS.str("Hotel Abruzzi, Piazza della Rotonda, 69, 00186 Rome, Italy");
	//Extract into these variables:
	string hotelName = "";
	string streetName = "";
	int streetNum;
	string zipcode;
	string city = "";
	string country = "";

	mySS.skipws;
	getline(mySS, hotelName, ',');
	getline(mySS, streetName, ',');
	mySS >> streetNum;
	mySS.ignore(2);
	mySS >> zipcode;
	getline(mySS, city, ',');
	mySS >> country;

	cout << "Hotel Name: " << hotelName << endl;
	cout << "Street Name: " << streetName << endl;
	cout << "Street Number: " << streetNum << endl;
	cout << "Zipcode: " << zipcode << endl;
	cout << "City: " << city << endl;
	cout << "Country: " << country << endl;

	return 0;
}
