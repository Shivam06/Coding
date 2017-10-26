#include<iostream>
#include<algorithm>
using namespace std;

int equalize(int wages[], int N) {
	int total = 0, min, max, diff;
	min = *min_element(wages, wages + N);
	do {
		max = *max_element(wages, wages + N);
		diff = max - min;
		total += diff;
		int flag = 0;
		for (int i = 0; i < N; i++) {
			if (wages[i] == max && !flag) {
				flag = 1;
				continue;
			}
			wages[i] += diff;
		}
		min = max;
	}while(diff != 0);
	return total;
}

int main() {
	int T, N;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>N;
		int wages[N];
		for (int i = 0; i < N; i++)
			cin>>wages[i];
		cout << equalize(wages, N) << endl;
		//cout << *min_element(wages, wages + N) << endl;
	}
	return 0;
}