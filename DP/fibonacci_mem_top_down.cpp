#include<iostream>
#include<map>
using namespace std;

int fib(int n) {
	static map<int, int> m;
	if (n <= 1) {
		m[n] = n;
		return n;
	}
	if (m[n])
		return m[n];
	else {
		m[n] = fib(n-1) + fib(n-2);
		return m[n];
	} 
}

int main() {
	cout << fib(11) << endl;
	return 0;
}