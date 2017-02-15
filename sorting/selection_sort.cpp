#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void selection_sort(int arr[], int n, int x) {
	int count = 0;
	for (int i = 0; i<n-1; i++) {
		int min = INT_MAX;
		int min_index = INT_MAX;
		for (int j = i; j <=n-1; j++) {
			if(arr[j]<min) {
				min = arr[j];
				min_index = j;
			}
		}
		swap(arr[min_index],arr[i]);
		count++;
		if (count == x)
			return;
	}
	
}

int main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];
    for (int i = 0; i< n; i++)
    	cin>>arr[i];
    selection_sort(arr, n, x);
    for (int i = 0; i<n; i++)
    	cout << arr[i] << " ";
    return 0;
}