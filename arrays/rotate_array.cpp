#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate_array(vector<int> v, int d) {
	int n = v.size();
	vector<int> output(n);
	int inv_d = n - d;
	for (int i = 0; i < n; i++) {
		output[(i+inv_d)%n] = v[i];
	}
	return output;
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
	v = rotate_array(v, d);
	cout << endl;

	for (int i =0; i<n; i++) {
		cout << v[i] << " ";
	}
	return 0;
}