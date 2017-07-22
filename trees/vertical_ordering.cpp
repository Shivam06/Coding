#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int arr[5] = {4,2,9,3,1};
	vector<int> v(arr, arr+5);
	string str = "";
	for (int i=0; i < v.size(); i++)
		str += string(v[i]);
	cout << string(5) << endl;
	return 0;

}