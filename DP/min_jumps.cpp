#include<iostream>
#include<climits>
using namespace std;


int min_jumps(int arr[], int n, int idx, int dp[]) {
	if (idx == 0){
		//cout << "h" << endl;
		return 0;
	}

	if (dp[idx])
		return dp[idx];

	int min_jump = INT_MAX, jump;
	for (int i = 0; i < idx; i++) {
		if (idx-i <= arr[i]) {
			//cout << i << endl;
			jump = min_jumps(arr, n, i, dp) + 1;
			if (min_jumps(arr, n, i, dp) == -1)
			    jump = -1;
			else
			    jump = min_jumps(arr, n, i, dp) + 1;
			//cout << "jump " << jump << endl;
			if (min_jump > jump)
				min_jump = jump;
		}
		else
			continue;
	}
	//cout << min_jump << endl;
	if (min_jump == INT_MAX)
	    min_jump = -1;
	dp[idx] = min_jump;
	return dp[idx];
}

int main() {
    int T, num, n;
    cin>>T;
    while (T--) {
    	cin>>n;
    	int arr[n];
    	for (int i = 0; i < n; i++) {
    	    cin>>num;
    	    arr[i] = num;
    	}
    	int dp[n] = {0};
    	cout << min_jumps(arr, n, n-1, dp) << endl;
    }
	return 0;
}