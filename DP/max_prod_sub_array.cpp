#include<iostream>
#include<vector>
using namespace std;

int find_max_prod_subarray(vector<int>& v) {
	int p1 = 1, p2 = 1, p3 = 1, i = 0;
	while (v[i] > 0) {
		p1 *= v[i];
		i++;
	}
	int n = v.size(), j = n-1;
	while (v[j] > 0) {
		p2 *= v[j];
		j--;
	}
	if (i == j) {
		return max(p1, p2);
	}
	else {
		p1 = p1*v[i];
		p2 = p2*v[j];
		int p = min(p1, p2);
		int count_neg = 0;
		for (i = i+1; i < j; i++) {
			p3 *= v[i];
		}
		if (p3 < 0)
			return p3*p;
		else 
			return p3*p1*p2;
	}
}

int main() {
	int arr[] = {4,-1,-2,1,5,-2,-6,-3};
	int n = sizeof(arr)/sizeof(int);
	vector<int> v(arr, arr+n);
	cout << find_max_prod_subarray(v);
}