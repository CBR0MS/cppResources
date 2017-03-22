#include <iostream>

using namespace std;

void toh(int n, int sourceN1, int destN3, int intermN2) {

	if (n > 0) {

		toh(n - 1, sourceN1, intermN2, destN3);
		cout << "Move disk " << n << " from needle " << sourceN1 << " to needle " << destN3 << endl;
		toh(n - 1, intermN2, destN3, sourceN1);
	}
}

int main() {

	toh(16, 1, 2, 3);

	return 0;
}
