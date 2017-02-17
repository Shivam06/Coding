#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int arr[], int n, int idx) {  // heapify function created
	int i = idx;
	int j = 2*i;

	while (j+1 < n) {
		if (arr[j] < arr[i] || arr[j+1] < arr[i]) {
			if (arr[j] < arr[j+1]) {
				swap(arr[i],arr[j]);
				i = j;
			}
			else {
				swap(arr[i],arr[j+1]);
				i = j + 1;
			}
			j = 2*i;
		}
		else
			break;
	}
	if (j < n) {
		if(arr[j] < arr[i])
			swap(arr[j], arr[i]);
	}
}

void arr_to_heap(int arr[], int n) {
	for(int i = n/2; i>=0; i--) {
		heapify(arr, n, i);
	}     
}

int* heap_sort(int arr[], int n) {
	arr_to_heap(arr,n);
	int* sorted_arr = new int[n-1];
	int i = n;
	while(i>1) {
		sorted_arr[n-i] = arr[1];
		swap(arr[i-1], arr[1]);
		heapify(arr, i-1, 1);
		i--;
	}
	return sorted_arr;
}

int main() {
	int arr[] = {0,6,4,2,1,8,3,0};
	int n = sizeof(arr)/sizeof(int);
	cout << n << endl;
	//arr_to_heap(arr, n);
	int* arr2 = heap_sort(arr, n);
	for(int i = 0; i < 7; i++)
		cout << arr2[i] << " ";
	return 0;
}