#include<iostream>
#include<algorithm>
using namespace std;



int find_pivot(int arr[], int start, int end) {
	int piv = end, flag = 0;
	for (int i = start; i<=end - 1; i++) {            // Mistake - 1 : Obviously can't start from 0
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

	for (; piv<end-1;) {  
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
	return piv;    
}

int random_partition(int arr[], int start, int end) {   // Randomized Partition - Nice Way
	int n = end - start + 1;
	int new_pivot = start + rand()%n;
	swap(arr[new_pivot], arr[end]);
	return find_pivot(arr, start ,end);
}

void quick_sort(int arr[], int start, int end) {
	int n = end - start + 1;
	if (n <= 1)                              // Mistake 2 : n can be lesser than 1 as well as when pivot is last or first element.
		return;
	int piv = find_pivot(arr, start, end);
	quick_sort(arr, start, piv-1);
	quick_sort(arr, piv+1, end);
}

int main() {
	int arr[] = {9,8,7,6,5,4,3,2,1};
	quick_sort(arr, 0, 8);
	for (int i = 0; i<9; i++)
		cout << arr[i] <<" ";

	return 0;
}