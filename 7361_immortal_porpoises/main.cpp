#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

long long fib(long long i_n){
	long long first = 0, second = 1, third;
	for(long long j=0; j<=i_n; j++){
		if(j <= 1){
			third = j;
		} else {
			third = first + second;
			first = second;
			second = third;
		}
	}

	third = third % 1000000000;
	// if(third >= 1000000000){
	// 	third -= 1000000000;
	// }

	if(third == 0 && i_n > 3){
		third = 1;
	}

	return third;
}

int main(){
	int i_dataset_num;
	cin >> i_dataset_num;

	vector<long long> v_dataset;
	cout << "v_dataset size: " << sizeof(v_dataset) << endl;

	for(int j=0; j<i_dataset_num; j++){
		int i_dataset;
		long long i_year;
		cin >> i_dataset >> i_year;
		// cout << "line: " << j << ", " << i_dataset << " " << i_year<<endl;
		v_dataset.push_back(i_year);
	}

	long long i_ten_prime_nine = pow(10,9);
	cout << "10^9: " << i_ten_prime_nine <<endl;
	cout << "v_dataset size: " << sizeof(v_dataset) << endl;

	for(int j=0; j<i_dataset_num; j++){
		long long i_result = fib(v_dataset[j]);
		cout << "year: " << v_dataset[j] << endl;
		cout << j+1 << " " << i_result << endl;
	}
	//cout << fib(8) << endl;
}