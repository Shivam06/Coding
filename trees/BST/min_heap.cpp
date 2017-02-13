#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int*& arr, int idx) {
	int n = 7;
	int i = idx;
	int j = 2*i;

	while (j+1 < n) {
		cout << "j = " << j <<endl;
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
	cout << arr[j] << endl;
	cout << arr[i] << endl;
	if (j < n) {
		if(arr[j] < arr[i])
			swap(arr[j], arr[i]);
	}
}

int main() {
	int arr[] = {0,8,4,2,6,9,1};
	int* ptr_arr = arr;
	heapify(ptr_arr, 1);
	for(int i = 1; i < 7; i++)
		cout << ptr_arr[i] << " ";
	return 0;
}