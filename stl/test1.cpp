#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
#define all(c) c.begin(), c.end()  

int main() {
	int arr[] = {2,4,6,8};
	vector<int> v1(arr, arr+4);
	vector<int> v2;
	v1.insert(v1.begin(), 1);
	for (auto itr = v1.begin(); itr != v1.end(); itr++)
		cout << *itr << endl;
	return 0;
}