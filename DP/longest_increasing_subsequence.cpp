#include<iostream>
#include<climits>
using namespace std;

int longest_increasing_sub_helper(int arr[], int n, int idx, int dp[]) {
	if (dp[idx])
		return dp[idx];


	int sum, max_sum = INT_MIN;

	for (int i = 0; i < idx; i++) {
		if (arr[i] < arr[idx]) {
			sum  = longest_increasing_sub_helper(arr, n, i, dp) + arr[idx];
			if (max_sum < sum)
				max_sum = sum;
		}
		else
			continue;													
	}
	if (max_sum == INT_MIN) {
		max_sum = arr[idx];
	}

	dp[idx] = max_sum;
	return dp[idx];
}


int longest_increasing_sub(int arr[], int n, int dp[]) {
	dp[0] = arr[0];
	int max = INT_MIN;
	for (int i = n-1; i >= 0; i--) {
		int a = longest_increasing_sub_helper(arr, n, i, dp);
		if (max < a)
			max = a;
	}
	return max;
}


int main() {
	int arr[] = {10, 5, 4, 3};
	int n = sizeof(arr)/sizeof(int);
	int dp[n] = {0};
	cout << longest_increasing_sub(arr, n, dp) << endl;
	return 0;
}