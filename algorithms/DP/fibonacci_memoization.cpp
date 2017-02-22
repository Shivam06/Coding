#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


int fib(int n, map<int, int> memo) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (memo.find(n) != memo.end())
		return memo[n];
	
	int f = fib(n-1, memo) + fib(n-2, memo);
	memo[n] = f;
	return f;
}

int main() {
	map<int, int> memo;
	for (int i = 1; i <= 10; i++)
		cout << fib(i, memo) << " ";
	return 0;
}