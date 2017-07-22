#include<iostream>
#include<vector>
using namespace std;

void rotate_array(vector<int>& v, int d) {
	int n = v.size();
	int i =0;
	int temp = v[i];
	for (int count = 0; count < n - 1; count++) {
		v[i] = v[(i+d)%n];
		i += d;
	}
	v[i] = temp;
}

int main() {
	vector<int> v;
	int n, num, d;
	cin>>n;
	cin>>d;
	for (int i = 0; i<n; i++) {
		cin>>num;
		v.push_back(num);
	}	
	rotate_array(v, d);
	cout << endl;
	for (int i =0; i<n; i++) {
		cout << v[i] << " ";
	}
	return 0;
}