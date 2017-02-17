#include <iostream>
#include<algorithm>
using namespace std;

int count_max_bottles(int sizes[], int n, int X) {
	sort(sizes, sizes + n);
	int sum = 0, count = 0;
	int i = 0;
	while (i<n) {
		sum += sizes[i++];
		if(sum <= X)
			count++;
		else
			break;
	}
	return count;
}

int main() {
	int T, n, X;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>n>>X;
		int bottle_sizes[n];
		for (int j = 0; j<n; j++)
			cin>>bottle_sizes[j];
		cout << count_max_bottles(bottle_sizes, n, X) << endl; 
	}
}