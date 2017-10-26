#include<iostream>
using namespace std;

int isWolverine(int minions[], int N, int K) {
	int count = 0;
	for (int i = 0; i<N; i++) {
		minions[i] = minions[i] + K;
		if (minions[i]%7==0)
			count++;
	}
	return count;
}

int main() {
	int T, N, K;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>N>>K;
		int minions[N];
		for (int j = 0; j < N; j++) {
			cin>>minions[j];
		}
		cout << isWolverine(minions, N, K) << endl;
	}
}