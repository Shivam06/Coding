#include<iostream>
#include<vector>
using namespace std;

int edit_distance_helper(string s1, string s2, int m, int n, int**& dp) {

	if (n == 0 || m == 0) {
		if (m == n) {
			if (s1[m] == s2[n])
				return 0;
			else
				return 1;
		}
		else {
			return max(m,n);
		}
	} 

	if (dp[m][n]) {
		return dp[m][n];
	}
	else {
		if (s1[m] == s2[n]) {
			dp[m][n] = edit_distance_helper(s1, s2, m-1, n-1, dp);
			return dp[m][n];
		}
		
		else {
			dp[m][n] = min(edit_distance_helper(s1, s2, m-1, n-1,dp), min(edit_distance_helper(s1, s2, m-1, n,dp), edit_distance_helper(s1, s2, m, n-1,dp))) + 1;
			return dp[m][n];
		}
	}
}

int edit_distance(string s1, string s2, int m, int n) {
	int** dp = new int*[m+1];
	for (int i = 0; i < m+1; i++) 
		dp[i] = new int[n+1];
	return edit_distance_helper(s1, s2, m, n, dp);
}

int main() {
	int t;
	cin>>t;
	string str1, str2;
	for (int i = 0; i < t; i++) {
		cout << "Enter next set of strigs" << endl;
		cin>>str1;
		cin>>str2;
		int m = str1.size(), n = str2.size();
		cout << edit_distance(str1, str2, m-1, n-1) << endl;
	}
	return 0;
}