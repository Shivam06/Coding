#include<iostream>
using namespace std;

string isPossible(int arr[], int N, long long C) {
	int i = 0;
	int sum = 0;
	while (C >= 0 && i<N) {
		C -= arr[i];
		i++;
	}
	if (C >= 0)
		return "Yes";
	else
		return "No";
}

int main() {
	int T, N;
	long long C;	
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>N>>C;
		int arr[N];
		for (int i = 0; i < N; i++)
			cin>>arr[i];
		cout << isPossible(arr, N, C) << endl;
	}
	return 0;
}