#include<iostream>
#include<climits>
using namespace std;

int longest_common_substring(string s1, int n1, int idx1, string s2, int n2, int idx2, int**& dp) {
	if (idx1 < 0 || idx2 < 0)
		return 0;
	if (idx1 == 0 && idx2 == 0) {
		if (s1[idx1] == s2[idx2]) {
			dp[idx1][idx2] = 1;
			return 1;
		}
		else {
			dp[idx1][idx2] = 0;
			return 0;
		}
	}

	if(dp[idx1][idx2] != 0)
		return dp[idx1][idx2];
	if (s1[idx1] == s2[idx2]) {
		dp[idx1][idx2] = longest_common_substring(s1,n1,idx1-1,s2,n2,idx2-1,dp) + 1;
		return dp[idx1][idx2];
	}	
	else {
		/dp/[idx1][idx2] = max(longest_common_substring(s1,n1,idx1-1,s2,n2,idx2,dp), longest_common_substring(s1,n1,idx1,s2,n2,idx2-1,dp));
		return 0;
	}
}

void display(int** dp, int n1, int n2) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int lcs(string s1, int n1, string s2, int n2) {
	int** dp;
	dp = new int*[n1];
	for (int i = 0; i < n1; i++)
		dp[i] = new int[n2];
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			dp[i][j] = 0;
		}
	}

	int len, max_len = INT_MIN;

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			len = longest_common_substring(s1, n1, i, s2, n2, j, dp);
			display(dp,n1,n2);
			cout << endl << endl;
			if (len > max_len)
				max_len = len;
		}
	}

	return max_len;
}

int main() {
	string str1, str2;
	str1 = "egegege";
	str2 = "eeeee";
	int n1 = str1.size(), n2 = str2.size();
	
	cout << lcs(str1, n1, str2, n2) << endl;
	return 0;
}