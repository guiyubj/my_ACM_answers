#include <iostream>

using namespace std;

int main(){
	//get dataset number
	short i_dataset_num;
	cin >> i_dataset_num;
	
	//create a dataset that have position for twince the dataset number
	short arr_dataset[i_dataset_num << 1];
	
	//start get input of data and at the same time solve problem
	short i_brain_eat;
	short i_brain_required;
	for(short j=0; j<i_dataset_num; j++){
		cin >> i_brain_eat >> i_brain_required;
		arr_dataset[j << 1] = i_brain_eat;
		arr_dataset[(j << 1) + 1] = i_brain_required;

		if(arr_dataset[j << 1] < arr_dataset[(j << 1) + 1]){
			cout << "NO BRAINS\n";
		} else {
			cout << "MMM BRAINS\n";
		}
	}
}
