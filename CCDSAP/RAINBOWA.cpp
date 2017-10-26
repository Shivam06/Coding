#include<iostream>
#include<string>
using namespace std;

string isRainbow(int A[], int N) {
	if (A[0] != A[N-1] || A[0] != 1)
		return "no";
	int start = 1, end = N-2;
	if (A[N/2] != 7)
		return "no";

	while (start <= end) {
		if (A[start] != A[end])
			return "no";
		if (A[start] != A[start - 1] + 1 && A[start] != A[start-1])
			return "no";
		start++;
		end--;
	}

	return "yes";
}

int main() {
	int T,N;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>N;
		int A[N];
		for (int i = 0; i < N; i++)
			cin>>A[i];
		cout << isRainbow(A, N) << endl;
	}
}