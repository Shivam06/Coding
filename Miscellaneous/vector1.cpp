#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	for(vector<int>::iterator itr = v.begin(); itr!= v.end(); itr++) {
		cout << *itr <<endl;
	}
	return 0;
}