#include <iostream>

using namespace std;

int main(){
	//get and store dataset num
	int i_num_dataset;
	cin >> i_num_dataset;

	//start processing input
	short i_cents;
	for(int j=0; j<i_num_dataset; j++){
		cin >> i_cents;
		short arr_changes[4];
	
		//calc quarter
		arr_changes[0] = i_cents / 25;
		//calc dime
		arr_changes[1] = (i_cents - arr_changes[0] * 25) / 10;
		//calc nickel
		arr_changes[2] = (i_cents - arr_changes[0] * 25 \
			- arr_changes[1] * 10) / 5;
		//calc penny
		arr_changes[3] = i_cents - arr_changes[0] * 25 \
			- arr_changes[1] * 10 - arr_changes[2] * 5;
		
		//output result
		cout << j+1 << " " << arr_changes[0] << " QUARTER(S), " \
		<< arr_changes[1] << " DIME(S), " << arr_changes[2] << " NICKEL(S), " \
		<< arr_changes[3] << " PENNY(S)" <<endl;
	}
}
