#include <iostream>
// #include <cmath>

using namespace std;

int main() {
	//pre-calculated digits numbers
	int arr_digits[] = 
	{
		9, 
		189, 
		2889, 
		38889, 
		488889, 
		5888889, 
		68888889, 
		788888889, 
		2000000001
	};

	int arr_maxs[] = 
	{
		9, 
		99, 
		999, 
		9999, 
		99999, 
		999999, 
		9999999, 
		99999999, 
		999999999
	};

	//function used to calc pre-calced array of digits
	// long long i_sum = 0;
	// for (int i = 1; i <= 20; i++) {
	// 	i_sum += 9 * i * pow(10, i - 1);
	// 	cout << i_sum << endl;
	// }

	//get digits numbers
	int i_digits;
	while (cin.peek() != '#' && cin >> i_digits) {
		int i_remaining;
		int i_index = 7;
		for (;i_index >= 0; i_index--) {
			if (i_digits > arr_digits[i_index]) {
				i_remaining = i_digits - arr_digits[i_index];
				break;
			}
		}

		//cout
		if (i_remaining % (i_index + 2)) {
			cout << "Impossible!" << endl;
		}
		else {
			cout << arr_maxs[i_index] + i_remaining / (i_index + 2) << endl;
		}
	
	}

	cin.get();
	cin.get();
	cin.get();
	return 0;
}