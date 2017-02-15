#include<iostream>
#include<algorithm>
using namespace std;

int bubble_sort(int arr[], int n) {
	int count = 0;
	for (int i = n-1; i>=1; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				count++;
			}
			else
				continue;
		}
	}
	return count;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
		cin>>arr[i];
	cout << bubble_sort(arr, n) << endl;
	for (int i =0; i< n; i++)
		cout << arr[i] << " ";
	cin>>n;
	return 0;
}