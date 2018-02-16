#include<iostream>
#include<vector>
using namespace std;

int coin_change(int coins[], int n, int sum) {
	if (sum == 0) {
		return 1;
	}
	if (n == 0)
		return 0;

	if (coins[n-1] > sum) {
		return coin_change(coins, n-1, sum);
	}
	else {
		return coin_change(coins, n-1, sum) + coin_change(coins, n, sum - coins[n-1]);
	}
}

int coin_change_mem(int coins[], int n, int sum) {
	static vector<vector<int> > dp(sum+1, vector<int> (n+1));

	if (sum == 0)
		return 1;

	if (n == 0)
		return 0;

	if (dp[sum][n])
		return dp[sum][n];

	if (coins[n-1] > sum) {
		dp[sum][n] = coin_change_mem(coins, n-1, sum);
	}
	else {
		dp[sum][n] = coin_change_mem(coins, n-1, sum) + coin_change_mem(coins, n, sum - coins[n-1]);
	}
	return dp[sum][n];
}

int main() {
	int coins[] = {1, 2,3};
	int n = 3, sum = 4;
	cout << coin_change_mem(coins, n, sum) << endl;
	return 0;
 }
