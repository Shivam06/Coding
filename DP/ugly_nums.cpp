#include<iostream>
#include<vector>
using namespace std;

int ugly(int n) {
	vector<int> v(n);
	v[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	int next_multiple_2 = 2, next_multiple_3 = 3, next_multiple_5 = 5;
	for (int i = 1; i < n; i++) {
		v[i] = min(next_multiple_2, min(next_multiple_5, next_multiple_3));
		if (v[i] == next_multiple_5) {
			i5 += 1;
			next_multiple_5 = v[i5]*5;
		}
		if (v[i] == next_multiple_3) {
			i3++;
			next_multiple_3 = v[i3]*3;
		}
		if (v[i] == next_multiple_2) {
			i2++;
			next_multiple_2 = v[i2]*2;
		}
	}
	return v[n-1];
}

int main() {
	int n = 15;
	cout << ugly(n) << endl;
	return 0;
}