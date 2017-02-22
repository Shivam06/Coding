#include<iostream>
#include<algorithm>
using namespace std;

int fib(int n) {
	int fib_arr[2];
	fib_arr[0] = 0;          // Space complexity reduced to O(1)
	fib_arr[1] = 1;
	if (n<2)
		return fib_arr[n-1];
	for (int i = 2; i < n; i++) {
		fib_arr[0] = fib_arr[0] + fib_arr[1];
		swap(fib_arr[0], fib_arr[1]);
	}
	return fib_arr[1];
}

int main() {
	for (int i = 1; i <=5; i++)
		cout << fib(i) << " ";
	return 0;
}