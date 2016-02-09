#include <iostream>

using namespace std;

int main() {
	// cout.setf(ios::hex, ios::basefield);
	// cout.unsetf(ios::showbase);
	while (true) {
		short arr_mem[256];
		char c_temp;
		for (int i_cursor = 0; i_cursor < 256; i_cursor++) {
			//receive a word
			cin >> c_temp;

			//put work into arr_mem
			if (c_temp == '0') {
				arr_mem[i_cursor] = 0;
			}
			if (c_temp == '1') {
				arr_mem[i_cursor] = 1;
			}
			if (c_temp == '2') {
				arr_mem[i_cursor] = 2;
			}
			if (c_temp == '3') {
				arr_mem[i_cursor] = 3;
			}
			if (c_temp == '4') {
				arr_mem[i_cursor] = 4;
			}
			if (c_temp == '5') {
				arr_mem[i_cursor] = 5;
			}
			if (c_temp == '6') {
				arr_mem[i_cursor] = 6;
			}
			if (c_temp == '7') {
				arr_mem[i_cursor] = 7;
			}
			if (c_temp == '8') {
				arr_mem[i_cursor] = 8;
			}
			if (c_temp == '9') {
				arr_mem[i_cursor] = 9;
			}
			if (c_temp == 'A') {
				arr_mem[i_cursor] = 10;
			}
			if (c_temp == 'B') {
				arr_mem[i_cursor] = 11;
			}
			if (c_temp == 'C') {
				arr_mem[i_cursor] = 12;
			}
			if (c_temp == 'D') {
				arr_mem[i_cursor] = 13;
			}
			if (c_temp == 'E') {
				arr_mem[i_cursor] = 14;
			}
			if (c_temp == 'F') {
				arr_mem[i_cursor] = 15;
			}
		}

		short i_cursor = 0;
		short i_acc_a = 0;
		short i_acc_b = 0;
		{
			if (arr_mem[0] == 8) {
				return 0;
			}
			label_start_process:
			while (i_cursor < 256) {
			//process a word
				//LD: Load accumulator A with the contents of memory at the specified argument.
				if (arr_mem[i_cursor] == 0) {
					i_acc_a = arr_mem[(arr_mem[i_cursor+1] << 4) + arr_mem[i_cursor+2]];
					// cout << "0" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					i_cursor += 3;
					goto label_start_process;
				}

				//ST: Write the contents of accumulator A to the memory location specified by the argument.
				if(arr_mem[i_cursor] == 1) {
					arr_mem[(arr_mem[i_cursor+1] << 4) + arr_mem[i_cursor+2]] = i_acc_a;
					// cout << "1" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					i_cursor += 3;
					goto label_start_process;
				}

				//SWP: Swap the contents of accumulators A and B.
				if(arr_mem[i_cursor] == 2) {
					short i_swap_temp = i_acc_a;
					i_acc_a = i_acc_b;
					i_acc_b = i_swap_temp;
					// cout << "2" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					i_cursor++;
					goto label_start_process;
				}

				//ADD: Add the contents of accumulators A and B. The low word of the sum is stored in A, and the high word in B.
				if (arr_mem[i_cursor] == 3) {
					short i_add_temp = i_acc_a + i_acc_b;
					i_acc_b = i_add_temp >> 4;
					i_acc_a = i_add_temp - (i_acc_b << 4);
					// cout << "3" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					i_cursor++;
					goto label_start_process;
				}

				//INC: Increment accumulator A. Overflow is allowed; that is, incrementing F yields 0.
				if (arr_mem[i_cursor] == 4) {
					i_acc_a++;
					if (i_acc_a > 16) {
						i_acc_a -= 16;
					}
					// cout << "4" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					i_cursor++;
					goto label_start_process;
				}

				//DEC: Decrement accumulator A. Underflow is allowed; that is, decrementing 0 yields F.
				if (arr_mem[i_cursor] == 5) {
					i_acc_a--;
					if (i_acc_a < 0) {
						i_acc_a += 16;
					}
					// cout << "5" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					i_cursor++;
					goto label_start_process;
				}

				//	BZ: If accumulator A is zero, the next command to be executed is at the location specified by the argument. If A is not zero, the argument is ignored and nothing happens.
				if (arr_mem[i_cursor] == 6) {
					if (i_acc_a == 0) {
						i_cursor = (arr_mem[i_cursor+1] << 4) + arr_mem[i_cursor+2];
					}
					else {
						i_cursor += 3;
					}
					// cout << "6" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					goto label_start_process;
				}

				//BR: The next command to be executed is at the location specified by the argument.
				if (arr_mem[i_cursor] == 7) {
					i_cursor = (arr_mem[i_cursor+1] << 4) + arr_mem[i_cursor+2];
					// cout << "7" <<"a: " << i_acc_a <<" b: " <<i_acc_b <<endl;
					goto label_start_process;
				}

				//STP: Stop execution of the program.
				if (arr_mem[i_cursor] == 8) {
					break;
				}

				//end all instruction
			}
		}

		//print execution result(mem dump)
		for (int i_cursor = 0; i_cursor < 256; i_cursor++) {
			cout << hex << uppercase << arr_mem[i_cursor];
		}
		cout << endl;
	}

	return 0;
}