#include<iostream>
#include<algorithm>
using namespace std;

int find_pivot(int arr[], int start, int end) {
	int piv = end, flag = 0;
	for (int i = start; i<=end - 1; i++) {
		if (arr[i]>arr[end]) {
			piv = i;
			flag = 1;
			break;
		}
		else
			continue;
	}
	if(!flag)
		return piv;

	for (; piv<end-1;) {  # 
		int flag = 0;
		for (int j = piv+1; j<end; j++) {
			if(arr[j] < arr[end]) {
				swap(arr[j], arr[piv]);
				piv++;
				flag = 1;
				break;
			}
			else
				continue;
		}
		if(!flag)
			break;
	}
	swap(arr[piv], arr[end]);
	return piv;    // Make it quicker by improving selection of pivot (randomized)
}

void quick_sort(int arr[], int start, int end) {
	int n = end - start + 1;
	if (n <= 1)
		return;
	int piv = find_pivot(arr, start, end);
	quick_sort(arr, start, piv-1);
	quick_sort(arr, piv+1, end);
}

int main() {
	int arr[] = {0,7,2,6,4,3,1,5};
	quick_sort(arr, 0, 7);
	for (int i = 0; i<8; i++)
		cout << arr[i] <<" ";

	return 0;
}