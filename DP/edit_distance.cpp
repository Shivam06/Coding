#include<iostream>
#include<vector>
using namespace std;

int edit_distance(string s1, string s2, int m, int n) {
	static vector<vector<int> > dp(m+1, vector<int> (n+1));

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
			dp[m][n] = edit_distance(s1, s2, m-1, n-1);
			return dp[m][n];
		}
		
		else {
			dp[m][n] = min(edit_distance(s1, s2, m-1, n-1), min(edit_distance(s1, s2, m-1, n), edit_distance(s1, s2, m, n-1))) + 1;
			return dp[m][n];
		}
	}
}

int main() {
	string s1 = "sunday";
	string s2 = "saturday";
	int m = s1.size(), n = s2.size();
	cout << edit_distance(s1, s2, m-1, n-1) << endl;
	return 0;
}