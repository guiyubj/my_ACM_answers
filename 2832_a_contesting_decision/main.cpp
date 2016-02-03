#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	//get input line numbers
	int i_dataset_num;
	cin >> i_dataset_num;

	//get and store input data
	std::vector<string> v_teamnames;
	std::vector<int> v_solved_problem_num;
	std::vector<int> v_penalty_points;

	string str_teamname;
	int arr_sub_and_time[9];
	int i_solved_problem_num;
	int i_penalty_points;
	for(int j=0; j<i_dataset_num; j++){
		//reset
		i_solved_problem_num = 0;
		i_penalty_points = 0;

		//get input into receive array
		cin >> str_teamname >> arr_sub_and_time[0] >> arr_sub_and_time[1] >> \
		arr_sub_and_time[2] >> arr_sub_and_time[3] >> \
		arr_sub_and_time[4] >> arr_sub_and_time[5] >> \
		arr_sub_and_time[6] >> arr_sub_and_time[7];

		//calc solved questions and penalty points
		for(short j=0; j<4; j++){
			if(arr_sub_and_time[j << 1 + 1] > 0){
				i_solved_problem_num++;
				cout << arr_sub_and_time[j << 1] << " " << arr_sub_and_time[j << 1 + 1];
				i_penalty_points += (arr_sub_and_time[j << 1] - 1) * 20;
				i_penalty_points += arr_sub_and_time[j << 1 + 1];
				cout << "penalty points: " << i_penalty_points <<endl;
			}
		}

		v_teamnames.push_back(str_teamname);
		v_solved_problem_num.push_back(i_solved_problem_num);
		v_penalty_points.push_back(i_penalty_points);
	}

	//find out which team have max questions solved
	short i_max_solved_problem = 0;
	for(int j=0; j<v_solved_problem_num.size(); j++){
		if(v_solved_problem_num[j] > i_max_solved_problem){
			i_max_solved_problem = v_solved_problem_num[j];
		}
	}

	std::vector<int> v_team_with_max_solved;
	for(int j=0; j<v_solved_problem_num.size(); j++){
		if(v_solved_problem_num[j] == i_max_solved_problem){
			v_team_with_max_solved.push_back(j);
		}
	}

	//find team with min penalty point
	int i_min_penalty_point = v_penalty_points[v_team_with_max_solved[0]];
	int i_winning_team = 0;
	for(int j=1; j<v_team_with_max_solved.size(); j++){
		if(v_penalty_points[v_team_with_max_solved[j]] < i_min_penalty_point){
			i_min_penalty_point = v_penalty_points[v_team_with_max_solved[j]];
			i_winning_team = j;
		}
	}

	cout << v_teamnames[v_team_with_max_solved[i_winning_team]] \
	<< " " << i_max_solved_problem << " " << i_min_penalty_point << endl;

}