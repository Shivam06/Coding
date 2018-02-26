#include<iostream>
#include<climits>
using namespace std;

int longest_increasing_subsequence_helper(int arr[], int n, int idx, int dp[]) {
	if (dp[idx])
		return dp[idx];

	int max_len = INT_MIN, len;
	for (int i = 0; i < idx; i++) {
		if (arr[i] < arr[idx]) {
			len = longest_increasing_subsequence_helper(arr, n, i, dp) + 1;
			if (len > max_len)
				max_len = len;
		}
		else
			continue;
	}

	if (max_len == INT_MIN) {
		dp[idx] = 1;
		return dp[idx];
	}

	dp[idx] = max_len;
	return dp[idx];
}

int longest_increasing_subsequence(int arr[], int n) {
	int dp[n] = {0};
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		longest_increasing_subsequence_helper(arr, n, i, dp);
	}

	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		cout << dp[i] << endl;
		if (max < dp[i]){
			max = dp[i];
		}
	}	

	return max;
}

int main() {
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(int);
	cout << longest_increasing_subsequence(arr, n) << endl;
	return 0;
}