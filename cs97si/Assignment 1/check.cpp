#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	int tmp = v[0];
	for (int i = 1; i < v.size() ; i++)
		v[i-1] = v[i]; 
	v.erase(v.end()-1);
	for (int i = 0; i<v.size() ; i++)
		cout << v[i] << endl;
}