
// Fibonacci generator
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class fibGen {
public:
	bool begin = true;

	int pre1 = 0;
	int pre2 = 0;

	int operator() () {

		if (begin && pre2 == 0) {
			pre2 = 1;
			return pre1;
		}
		if (begin && pre2 == 1) {
			begin = false;
			return pre2;
		}
		else {
			int cur = pre1 + pre2;
			pre1 = pre2;
			pre2 = cur;

			return cur;
		}
	}
};

int main() {


	vector<int> myVec(10);

	generate(myVec.begin(), myVec.end(), fibGen());
	copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));


	return 0;
}
