#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_max_subarray(vector<int>& v) {
	int cur = 0, ath = 0;
	for (int i = 0; i < v.size(); i++) {
		cur += v[i];
		if (cur < 0) {
			cur = 0;
			continue;
		}
		if (cur > ath) 
			ath = cur;
	}
	if (ath)
		return ath;
	else
		return *max_element(v.begin(), v.end());
}

int main() {
	int arr[] = {-2, -3, -4, -2, -8, -2, -3};
	int n = sizeof(arr)/sizeof(int);
	vector<int> v(arr, arr + n);
	cout << find_max_subarray(v) << endl;
	return 0;
}