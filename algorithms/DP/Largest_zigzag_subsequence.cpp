#include<iostream>
using namespace std;

int longest_zigzag(int A[], int n) {
	int increase[n+1], S[n+1];
	for (int i = 1; i<=n; i++)
		S[i] = 1;
	increase[1] = -1;

	for (int i = 2; i <=  n; i++) {
		for (int j = 1; j < i; j++) {
			if(increase[j] == -1) {
				if (A[j]< A[i]) {
					increase[i] = 1;
					S[i] = max(S[j] + 1,S[i]);
				}
				else if (A[j] > A[i]) {
					increase[i] = 0;
					S[i] = max(S[j] + 1,S[i]);
				}
				else 
					increase[i] = -1;
			}
			else if(increase[j] == 0) {
				if(A[j] < A[i]) {
					S[i] = max(S[j] + 1, S[i]);
					increase[i] = 1;
				}
			}
			else if (increase[j] == 1) {
				if (A[j] > A[i]){
					S[i] = max(S[j] + 1, S[i]);
					increase[i] = 0;
				}
			}
		}
	}
	return S[n];
}

int main() {
	int N;
	cin>>N;
	int A[N+1];
	for (int i =1; i <=N; i++)
		cin>>A[i];
	cout << longest_zigzag(A, N) << endl;
	return 0;
}