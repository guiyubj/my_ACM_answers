#include <iostream>

using namespace std;

//return 0 given the game unfinished, return the candy count if finished
int is_finish(int arr_candy[], int i_arr_size) {
	bool b_is_equal = true;
	int i_candy_de_first_stu = arr_candy[0];
	for(int j = 1; j < i_arr_size; j++) {
		if (arr_candy[j] != i_candy_de_first_stu) {
			b_is_equal = false;
			break;
		}
	}

	if (b_is_equal) {
		return i_candy_de_first_stu;
	}
	else {
		return 0;
	}
}

int main() {
	//get student count for each game
	int i_stu_cnt;
	while (true) {
		cin >> i_stu_cnt;
		if(i_stu_cnt == 0) {
			break;
		}

		//get candy count for each student
		int arr_candy[i_stu_cnt];
		for (int j = 0; j < i_stu_cnt; j++) {
			cin >> arr_candy[j];
		}

		//check if finished
		int i_round_cnt = 0;
		int i_finish_status = 0;
		int arr_candy_half[i_stu_cnt];
		while (!i_finish_status) {
			//start simulation
			for (int j = 0; j < i_stu_cnt; j++) {
				arr_candy_half[j] = arr_candy[j] / 2;
			}

			for (int j = 1; j < i_stu_cnt; j++) {
				arr_candy[j] = (arr_candy[j] / 2) + arr_candy_half[j - 1];
				if (arr_candy[j] % 2) {
					arr_candy[j]++;
				}
			}
			arr_candy[0] = (arr_candy[0] / 2) + arr_candy_half[i_stu_cnt - 1];
			if (arr_candy[0] % 2) {
				arr_candy[0]++;
			}

			i_round_cnt++;


			// cout << "\nround: " << i_round_cnt << " i_stu_cnt: " << i_stu_cnt<<endl;
			// for (int j = 0; j < i_stu_cnt; j++) {
			// 	cout << arr_candy[j] << " ";
			// }
			// cout << endl;
			// sleep(1);

			i_finish_status = is_finish(arr_candy, i_stu_cnt);
		}

		cout << i_round_cnt << " " << i_finish_status << endl;
	}
}