#include <iostream>
using namespace std;

int main() {

	try {

		int arrInd[5];

		for (int i = 0; i < 5; i++) {
			arrInd[i] = i + i;
		}

		int index;
		cout << "Enter an array index: ";
		cin >> index;

		if (index < 5) {
			cout << "value: " <<  arrInd[index];
		}
		else {
			out_of_range e("Out of bounds index");
			throw e;
		}
	}
	catch (const out_of_range& e) {

		cout << e.what();
	}

	return 0;
}
