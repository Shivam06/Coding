#include<iostream>
#include<vector>
using namespace std;

int ways_135(int n, vector<double>& mem) {
	if (n < 0)
		return 0;
	if (!mem[n]) {
		mem[n] =  ways_135(n-1, mem) + ways_135(n-3,mem) + ways_135(n-5,mem);
	}
	return mem[n];
}

int main() {
	int N = 50;
	vector<double	> arr(N+1,0);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	cout << ways_135(N, arr) << endl;
	return 0;
}