#include<iostream>
#include<vector>
#include<ctime>
#include<cstdio>
using namespace std;

int ways(int n) {
	if (n==0)
		return 1;
	if (n < 0)
		return 0;
	return ways(n-1) + ways(n-3) + ways(n-5);
}

long long ways_mem(int n) {
	static vector<long long> arr(n+1);
	if (n == 0) {
		arr[0] = 1;
		return arr[0];
	}
	else if (n<0)
		return 0;

	if (!arr[n])
		arr[n] = ways_mem(n-1) + ways_mem(n-3) + ways_mem(n-5);
	return arr[n];

}

int main() {
	const int n = 7;
	clock_t start = clock();
	cout << ways_mem(40) << endl;
	int t = clock() - start;
	printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	return 0;
}