#include <iostream>
#include<algorithm>
using namespace std;

void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j>0) {
			if (arr[j] < arr[j-1])
				swap(arr[j], arr[j-1]);
			else
				break;
			j--;
		}
	}
}

int find_index(int arr[], int x, int n) {
	for(int i=0; i<n; i++) {
		if(arr[i] == x)
			return i;
	}
}

int* sorted_indices(int arr[], int n) {
	int unsorted_arr[n];
	for(int i=0; i<n; i++)
		unsorted_arr[i] = arr[i];
	insertion_sort(arr, n);
	int* final_arr = new int[n];
	for (int i=0; i<n; i++) {
		int idx = find_index(unsorted_arr, arr[i], n);
		final_arr[i] = idx + 1;
	}
	return final_arr;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i<n; i++)  
    	cin>>arr[i];
    int* ptr = sorted_indices(arr, n);
    for (int i = 0; i<n; i++)
    	cout << ptr[i] << " ";
    return 0;
}