#include <iostream>

using namespace std;

int main() {
	//get digits numbers
	int i_digits;
	while (cin.peek() != '#' && cin >> i_digits) {
	// cin >> i_digits;
	cout << i_digits;
	}

	return 0;
}