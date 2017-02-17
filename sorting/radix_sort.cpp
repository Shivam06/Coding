#include<iostream>
using namespace std;

int max(int arr[], int n) {               // time complexity - O(n)
	int max_val = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max_val)
			max_val = arr[i];
		else
			continue;
	}
	return max_val;
} 

void count_sort(int arr[], int n, int rem) {  // time complexity - O(3n + b) ~ O(n+b) where b is range (10 here)
	int freq[10] = {0}, output[10];
	for (int i = 0; i < n; i++) {
		freq[(arr[i]/rem)%10]++;
	}

	for (int i=1; i<10; i++) 
		freq[i] = freq[i] + freq[i-1];

	for(int i = n-1; i>=0; i--) {
		output[freq[(arr[i]/rem)%10]-1] = arr[i];
		freq[(arr[i]/rem)%10]--;
	}

	for(int i = 0; i < n; i++)
		arr[i] = output[i];
}

void radix_sort(int arr[], int n) {  // time complexity - O((n+b)*log10(max(arr))) As log10(max(arr)) is number of digits in max value of array
	int rem = 1;
	int maxx = max(arr, n);
	while(maxx) {
		count_sort(arr, n, rem);
		maxx = maxx/10;
		rem = rem*10;
	}
}

int main() {
	int arr[] = {25, 11, 37, 14, 42, 6, 52};
	int n = sizeof(arr)/sizeof(int);
	radix_sort(arr, n);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}