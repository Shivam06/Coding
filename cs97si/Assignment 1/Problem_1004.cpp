#include<iostream>
#define N 12
using namespace std;

int main() {

	float sum = 0.0, balance;

	for (int i = 0; i<N; i++) {
		cin>>balance;
		sum += balance;
	}

	cout << "$" << sum/N;
	return 0;
}