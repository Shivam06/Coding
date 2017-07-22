#include<iostream>
#include<vector>
using namespace std;
#define traverse(container, itr) for (typeof(container.begin()) itr = container.begin(); itr != container.end(); itr++)


int main() {
	int arr[] = {5,2,4,9,1};
	vector<int> v1(arr, arr+5);
	int r = 0;
	traverse(v1, it) {
		r += *it;
	}
	cout << r << endl;
	return 0;
}