#include <iostream>
#include <string>

using namespace std;

int main() {
	//get line by line
	string str_line;
	while (getline(cin, str_line)) {
		if (str_line != "#") {
			//start to sum line by char
			int i_sum = 0;
			for (int j = 0; j != str_line.size() - 1; j++) {
				if (str_line[j] > 64 && str_line[j] < 91) {
					i_sum += int(str_line[j] - 64) * (j + 1);
				}
			}

			//print result
			cout << i_sum << endl;
		}
		else {
			// cin.ignore();
			return 0;
		}
	}
}