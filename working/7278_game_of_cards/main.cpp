#include <iostream>
#include <vector>
using namespace std;

int max_in_array(int a[]);

int main(){
	while(cin.peek() != EOF){
		std::vector<std::vector<int>> piles;
		int pile_num, k;
		cin >> pile_num >> k;
		int pile_card_num[pile_num];
	//set up vector sizes
		piles.resize(pile_num);

  //get input
		for(int i=0; i<pile_num; i++){
			cin >> pile_card_num[i];
			piles[i].resize(pile_card_num[i]);
			int poker;
			for(int j=0; j<pile_card_num[i]; j++){
				cin >> poker;
				piles[i][j] = poker;
			//cout << "\npoker : " << poker;
			}
		}


  //print input
	// cout << endl<< endl<<pile_num << k << endl;
		for(int i=0; i<pile_num; i++){
		// cout << "\nprinting pile: " << i << endl;
		// cout << "pile_card_num: " << pile_card_num[i] << endl;
			for(int x=0; x<pile_card_num[i]; x++){
			// cout << piles[i][x] << " ";
			}
		// cout << endl;
		}

  //start solving 
		int max_steps[pile_num];
		for(int i=0; i<pile_num; i++){
		// cout << "\ni = " << i << endl;
			int cursor = 0;
			int possible_steps[k+1];
			for(int j=0; j<=k; j++){
			//cout << "\nk = " << k << endl;
				int step_counter = 0;
				int top_card;
				cursor = 0;
			// cout << "\nj = " << j << endl;
				cursor += j;
			// cout << "\n cursor: " << cursor << ": " \
				<< piles[i][cursor] << endl;
				top_card = piles[i][cursor];
				cursor += top_card;
				while(cursor < pile_card_num[i]){
				// cout << "\n cursor: " << cursor << ": " \
					<< piles[i][cursor] << endl;
					step_counter++;
					top_card = piles[i][cursor];
					cursor += top_card;
				}
				possible_steps[j] = step_counter;
			}

		// cout << "\npossible_steps: \n";
			for(int y=0; y<sizeof(possible_steps)/sizeof(int); y++){
			// cout << possible_steps[y]<<endl;
			}

			max_steps[i] = max_in_array(possible_steps);
		}

	// cout << "\nmax_steps: \n";
		for(int i=0; i<sizeof(max_steps)/sizeof(int); i++){
		// cout << max_steps[i]<<endl;
		}

	//compare each piles' best stretagy
	//to determine if there are optimum stretagy(alice can win)
		bool bob_win = false;
	//int step = max_steps[0];
		int optimum_solution = max_in_array(max_steps);
	// cout << "optimum_solution : " << optimum_solution << endl;
		int optimum_solution_counter = 0;
		for(int i=0; i<sizeof(max_steps)/sizeof(int); i++){
			if(max_steps[i] == optimum_solution){
				optimum_solution_counter ++;
			}
		// cout << "optimum_solution_counter : " << optimum_solution_counter <<endl;
			if(optimum_solution_counter > 1){
				bob_win = true;
			}
		}

		if(bob_win){
			cout << endl << "Bob will win." << endl;
		}
		else{
			cout << endl << "Alice can win." << endl;
		}
	// char c;
	// cin.get(c);
	// cout << "\nFinal get: " << c << endl;
	// cin.get();

	}

	return 0;
}


int max_in_array(int a[]){
	int max = 0;
	int length = sizeof(a)/sizeof(int);
	//cout << "\nlength: \n" << length << endl;
	for(int i=0; i<length; i++){
		//cout << a[i] <<endl;
		if(a[i]>max){
			max = a[i];
		}
	}
	return max;
}

