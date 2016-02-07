#include <iostream>

using namespace std;

int main() {
	while (true) {
		short arr_mem[256];
		char c_temp;
		for (int i_cursor = 0; i_cursor < 256; i_cursor++) {
			//receive a word
			cin >> c_temp;
			arr_mem[i_cursor] = short(c_temp);
		}

		short i_cursor;
		short i_acc_a;
		short i_acc_b;
		{

			label_start_process:
			if (i_cursor < 256) {
			//process a word
				//LD: Load accumulator A with the contents of memory at the specified argument.
				if (arr_mem[i_cursor] == 0) {
					i_acc_a = arr_mem[(arr_mem[i_cursor+1] << 4) + arr_mem[i_cursor+2]];
					i_cursor += 3;
					goto label_start_process;
				}

				//ST: Write the contents of accumulator A to the memory location specified by the argument.
				if(arr_mem[i_cursor] == 1) {
					arr_mem[(arr_mem[i_cursor+1] << 4) + arr_mem[i_cursor+2]] = arr_mem[i_cursor];
					i_cursor += 3;
					goto label_start_process;
				}

				//SWP: Swap the contents of accumulators A and B.
				if(arr_mem[i_cursor] == 2) {
					short i_swap_temp = i_acc_a;
					i_acc_a = i_acc_b;
					i_acc_b = i_swap_temp;
					i_cursor++;
					goto label_start_process;
				}

				//ADD: Add the contents of accumulators A and B. The low word of the sum is stored in A, and the high word in B.
				if (arr_mem[i_cursor] == 3) {
					short i_add_temp = i_acc_a + i_acc_b;
					i_acc_b = i_add_temp >> 4;
					i_acc_a = i_add_temp - i_acc_b << 4;
					i_cursor++;
					goto label_start_process;
				}

				//INC: Increment accumulator A. Overflow is allowed; that is, incrementing F yields 0.
				if (arr_mem[i_cursor] == 4) {
					i_acc_a ++;
					if (i_acc_a >= 16) {
						i_acc_a -= 16;
					}
					i_cursor++;
					goto label_start_process;
				}

				//DEC: Decrement accumulator A. Underflow is allowed; that is, decrementing 0 yields F.
				if (arr_mem[i_cursor] == 5) {
					i_acc_a --;
					if (i_acc_a <= 0) {
						i_acc_a += 16;
					}
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
						goto label_start_process;
					}
				}

				//BR: The next command to be executed is at the location specified by the argument.
				if (arr_mem[i_cursor] == 7) {
					i_cursor = (arr_mem[i_cursor+1] << 4) + arr_mem[i_cursor+2];
				}

				//STP: Stop execution of the program.
				if (arr_mem[i_cursor] == 8) {
					i_cursor = 256;
				}

				//end all instruction
			}
		}

		//print execution result(mem dump)
		for (int i_cursor = 0; i_cursor < 256; i_cursor++) {
			cout << arr_mem[i_cursor];
		}
	}
}