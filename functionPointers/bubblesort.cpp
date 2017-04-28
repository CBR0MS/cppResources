// vector bubble sort 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


bool compare_gt(int a, int b) {   // returns true if a is greater than b

	if (a > b)
		return true;
	else
		return false;
}

bool compare_lt(int a, int b) { // returns true if a is less than b

	if (a < b)
		return true;
	else
		return false;
}

void bubbleSort(vector<int> &vec, bool(*compare) (int x, int y)) {

	for (int i = 1; i < vec.size(); i++) {

		for (int j = vec.size() - 1; j >= i; j--) {

			if (!compare(vec.at(j), vec.at(j - 1))) {

				swap(vec.at(j), vec.at(j - 1));
			}
		}
	}
}

int main() {


	vector<int> myVec;

	for (int i = 0; i < 10; i++) {
		myVec.push_back(rand() % 50);
	}

	cout << "Before sorting...\n";
	copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));

	cout << "\n\nSorted in non-increasing order...\n";
	bubbleSort(myVec, &compare_lt);
	copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));

	cout << "\n\nSorted in non-decreasing order...\n";
	bubbleSort(myVec, &compare_gt);
	copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));

	return 0;
}
