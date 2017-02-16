#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int max(int arr[], int n) {
	int max_val = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max_val)
			max_val = arr[i];
		else
			continue;
	}
	return max_val;
} 

void counting_sort(int arr[], int n) {
	int K = max(arr, n);
	int aug_arr[K+1];
	int sorted_arr[n];
	for (int i=0; i<K+1; i++)
		aug_arr[i] = 0;

	for (int i =0; i<n; i++) 
		aug_arr[arr[i]]++;

	int i = 0, k = 0;
	while(k<=K && i<=n-1) {
		for (int count=0; count<aug_arr[k]; count++) {
			arr[i] = k;
			i++;
		}
		k++;
	}
} 

int main() {
	int arr[] = {4,2,1,9,5,3,2,2,0,5};
	counting_sort(arr, 10);
	for (int i =0; i< 10; i++)
		cout << arr[i] << " ";
	return 0;
}