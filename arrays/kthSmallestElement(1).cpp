#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class comparater {

public:
	int operator() (int x, int y) {
		return x > y;
	}
};

int findKthElement(int arr[], int n, int k) {

	int flag;
	priority_queue<int> pq;
	priority_queue<int, vector<int>, comparater> pq1;
	if (k>n / 2) {
		flag = 0;
		for (int i = 0; i<n; i++) {
			pq.push(arr[i]);
		}
	}
	else {
		flag = 1;
		for (int i = 0; i<n; i++) {
			pq1.push(arr[i]);
		}
	}

	

	if (!flag) {
		for (int i = 1; i<n - k + 1; i++) {
			pq.pop();
		}
		return pq.top();
	}
	else {
		for (int i = 1; i<k; i++)
			pq1.pop();
		return pq1.top();
	}
}

int main() {
	int T, n, k;
	int* arr;
	cin >> T;
	for (int i = 0; i<T; i++) {
		cin >> n;
		arr = new int[n];
		for (int j = 0; j<n; j++)
			cin >> arr[j];
		cin >> k;
		cout << findKthElement(arr, n, k) << endl;
	}
	return 0;
}
