#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int M = pow(10,9) + 7;

int count_paths_helper(int m, int n, vector<vector<int> >& dp, int i, int j) {
	if (i == 1 && j == 1)
		return 1;

	if (dp[i][j] < 0)
		return 0; 
	if (dp[i][j] > 0)
		return dp[i][j];

	dp[i][j] = (count_paths_helper(m, n, dp, i-1, j)%M + count_paths_helper(m, n, dp, i, j-1)%M)%M;
	return dp[i][j];
}

int count_paths(int m, int n) {
	vector<vector<int> > dp(m+1, vector<int>(n+1,0));
	for (int i = 0; i <= n; i++) {
		dp[0][i] = -1;
	}
	for (int i = 0; i <= m; i++) {
		dp[i][0] = -1;
	}

	int idxi = m, idxj = n;
	return count_paths_helper(m, n, dp, idxi, idxj);
}	

int main() {
	int m, n;
	m = 100, n = 100;
	cout << count_paths(m, n) << endl;
	return 0;
}