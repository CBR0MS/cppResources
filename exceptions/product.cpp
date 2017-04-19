// ProductNotFoundException.hpp

#pragma once
#include <iostream>
#include <string>
using namespace std;

class ProductNotFoundException
{
public:
	ProductNotFoundException() { };
	ProductNotFoundException(string p_message) { message = p_message };
	string what() { return message; };

private:
	string message;
};

// Driver.cpp

#include <iostream>
#include <string>
#include "ProductNotFoundException.hpp"

using namespace std;

// Given function in the question. You need to throw a
// ProductNotFoundException instead of returning -1

// TODO: figure out how to return exception and int
int getProductID(int ids[], string names[], int numProducts, string target) throw(ProductNotFoundException)
{
	for (int i = 0; i < numProducts; i++)
	{
		if (names[i] == target)
			return ids[i];
	}
	return ProductNotFoundException("Exception: The product is not included in the array!"; //Not found
}

// Given test code in the question. You need to provide exception
// handling code in this main function

int main()
{
	int productIds[]{ 4, 5, 8, 10, 13 };
	string products[]{ "computer", "flash drive",
		"mouse", "printer", "camera" };

	cout << getProductID(productIds, products, 5, "mouse") << endl;
	cout << getProductID(productIds, products, 5, "camera") << endl;
	cout << getProductID(productIds, products, 5, "laptops") << endl;

	cout << endl;
	return 0;

}
