#include<iostream>
#include<algorithm>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
	int i = start, j = mid;
	int n = end - start + 1;
	int new_arr[n];
	int k = 0;
	while(i<=mid-1 && j<=end) {
		if (arr[i] < arr[j]) {
			new_arr[k++] = arr[i++];
		}
		else {
			new_arr[k++] = arr[j++];
		}
	}

	if (i != mid) {
		while (i<=mid-1) {
			new_arr[k++] = arr[i++];
		}
	}

	if (j!=end+1) {
		while (j<=end) {
			new_arr[k++] = arr[j++];
		}
	}
	for(int i = 0; i<n; i++)
		arr[start+i] = new_arr[i];
	//arr = new_arr;   why doesn't this work
}

void merge_sort(int arr[], int start, int end) {
	int n = end - start + 1;
	if(n==1)
		return;
	int mid = start + n/2;
	merge_sort(arr, start, mid-1);
	merge_sort(arr, mid, end);
	merge(arr, start, mid, end);
}


int main() {
	int arr[] = {1,8,2,6,5,3,0};
	merge_sort(arr, 0, 6);;
	for (int i=0; i<7; i++)
		cout << arr[i] << " ";
	return 0;
}