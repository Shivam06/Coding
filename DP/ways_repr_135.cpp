#include<iostream>
#include<vector>
using namespace std;

int ways(int n) {
	vector<int> v(n+1);
	int sum;
	for (int i = 1; i <= n; i++) {
		sum = v[i-1];
		i > 3 ? sum += v[i-3]: sum+=0;
		i > 4 ? sum += v[i-4]: sum+=0;
		i == 3 || i == 4 || i == 1? sum += 1:sum+=0;
		v[i] = sum;
	}
	return v[n];
}

int main() {
	int n=5;
	cout << ways(n) << endl;
	return 0;
}