#include <iostream>
#include <array>
#include <vector>

using namespace std;

array<long long, 3> calc(long long i_datum){
	array<long long, 3> arr_return = {0,0,0};

	for(long long j=1; j<=i_datum; j++){
		arr_return[0] += j;
	}

	long long i_loop = 0;
	long long i_counter = 0;
	while(i_counter < i_datum){
		if(i_loop%2){
			arr_return[1] += i_loop;
			i_counter++;
		}
		i_loop++;
	}

	i_loop = 0;
	i_counter = 0;
	while(i_counter <= i_datum){
		if(!(i_loop%2)){
			arr_return[2] += i_loop;
			i_counter++;
		}
		i_loop++;
	}

	return arr_return;
}

int main(){
	int i_dataset_num;
	cin >> i_dataset_num;

	vector<long long> v_dataset;

	for(int j=0; j<i_dataset_num; j++){
		int i_dataset;
		long long i_datum;
		cin >> i_dataset >> i_datum;
		v_dataset.push_back(i_datum);
	}


	for(int j=0; j<i_dataset_num; j++){
		array<long long, 3> arr_return = calc(v_dataset[j]);
		cout << j+1 << " " << arr_return[0] << " " << arr_return[1]\
		<< " " << arr_return[2] << endl;
	}
}