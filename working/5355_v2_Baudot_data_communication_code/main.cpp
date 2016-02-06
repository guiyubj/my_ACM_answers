#include <iostream>
#include <string>

using namespace std;

//compare input string with Baudot code and print conversion result
void print_char(const string& str_line, int& i_cursor, bool& b_shift) {
	string str_code = str_line.substr(i_cursor, 5);
	if (!b_shift) {
		if (str_code == "00000") {
			cout << '<';
		}
		if (str_code == "00001") {
			cout << 'T';
		}
		if (str_code == "00010") {
			cout << '*';
		}
		if (str_code == "00011") {
			cout << 'O';
		}
		if (str_code == "00100") {
			cout << ' ' ;
		}
		if (str_code == "00101") {
			cout << 'H';
		}
		if (str_code == "00110") {
			cout << 'N';
		}
		if (str_code == "00111") {
			cout << 'M';
		}
		if (str_code == "01000") {
			cout << '=';
		}
		if (str_code == "01001") {
			cout << 'L';
		}
		if (str_code == "01010") {
			cout << 'R';
		}
		if (str_code == "01011") {
			cout << 'G';
		}
		if (str_code == "01100") {
			cout << 'I';
		}
		if (str_code == "01101") {
			cout << 'P';
		}
		if (str_code == "01110") {
			cout << 'C';
		}
		if (str_code == "01111") {
			cout << 'V';
		}



		if (str_code == "10000") {
			cout << 'E';
		}
		if (str_code == "10001") {
			cout << 'Z';
		}
		if (str_code == "10010") {
			cout << 'D';
		}
		if (str_code == "10011") {
			cout << 'B';
		}
		if (str_code == "10100") {
			cout << 'S';
		}
		if (str_code == "10101") {
			cout << 'Y';
		}
		if (str_code == "10110") {
			cout << 'F';
		}
		if (str_code == "10111") {
			cout << 'X';
		}
		if (str_code == "11000") {
			cout << 'A';
		}
		if (str_code == "11001") {
			cout << 'W';
		}
		if (str_code == "11010") {
			cout << 'J';
		}
		if (str_code == "11011") {
			b_shift = false;
		}
		if (str_code == "11100") {
			cout << 'U';
		}
		if (str_code == "11101") {
			cout << 'Q';
		}
		if (str_code == "11110") {
			cout << 'K';
		}
		if (str_code == "11111") {
			b_shift = true;
		}
	}
	else {
		if (str_code == "00000") {
			cout << '>';
		}
		if (str_code == "00001") {
			cout << '5';
		}
		if (str_code == "00010") {
			cout << '@';
		}
		if (str_code == "00011") {
			cout << '9';
		}
		if (str_code == "00100") {
			cout << ' ';
		}
		if (str_code == "00101") {
			cout << '%';
		}
		if (str_code == "00110") {
			cout << ',';
		}
		if (str_code == "00111") {
			cout << '.';
		}
		if (str_code == "01000") {
			cout << '+';
		}
		if (str_code == "01001") {
			cout << ')';
		}
		if (str_code == "01010") {
			cout << '4';
		}
		if (str_code == "01011") {
			cout << '&';
		}
		if (str_code == "01100") {
			cout << '8';
		}
		if (str_code == "01101") {
			cout << '0';
		}
		if (str_code == "01110") {
			cout << ':';
		}
		if (str_code == "01111") {
			cout << ';';
		}



		if (str_code == "10000") {
			cout << '3';
		}
		if (str_code == "10001") {
			cout << '\"';
		}
		if (str_code == "10010") {
			cout << '$';
		}
		if (str_code == "10011") {
			cout << '?';
		}
		if (str_code == "10100") {
			cout << '#';
		}
		if (str_code == "10101") {
			cout << '6';
		}
		if (str_code == "10110") {
			cout << '!';
		}
		if (str_code == "10111") {
			cout << '/';
		}
		if (str_code == "11000") {
			cout << '-';
		}
		if (str_code == "11001") {
			cout << '2';
		}
		if (str_code == "11010") {
			cout << '\'';
		}
		if (str_code == "11011") {
			b_shift = false;
		}
		if (str_code == "11100") {
			cout << '7';
		}
		if (str_code == "11101") {
			cout << '1';
		}
		if (str_code == "11110") {
			cout << '(';
		}
		if (str_code == "11111") {
			b_shift = true;
		}
	}
	i_cursor += 5;
}

int main() {
	string str_line;
	getline(cin, str_line);
	getline(cin, str_line);

	//handle query
	bool b_shift;
	int i_cursor;
	while(getline(cin, str_line)) {
		b_shift = false;
		i_cursor = 0;

		while(i_cursor < str_line.size()) {
			print_char(str_line, i_cursor, b_shift);
		}
		cout << endl;
	}

  	return 0;
}
