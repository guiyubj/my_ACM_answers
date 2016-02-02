#include <iostream>
#include <vector>
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

	if(third == 0 && i_n > 3){
		third = 1;
	}

	return third;
}


int main(){
	int * p;
	cout << fib(3750000000) << endl;


}