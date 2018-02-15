#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
using namespace std;

int check_sum(int set[], int sum, int n) {
	if (sum == 0)
		return 1;
	if (n == 0 && sum > 0)
		return 0;

	if (set[n-1] > sum)
		return check_sum(set, sum, n-1);

	return check_sum(set, sum, n-1) || check_sum(set, sum - set[n-1], n-1);
}

int check_sum_mem(int set[], int sum, int n) {
	static vector<vector<int> > dp(sum+1, vector<int>(n+1, 0));
	cout << n << " " << sum << endl;
	if(sum == 0)
		return 1;
	if (n == 0 && sum > 0)
		return 0;

	if (dp[sum][n] == 1)
		return 1;

	if (set[n-1] > sum)
		dp[sum][n] = check_sum_mem(set, sum, n-1);

	else 
		dp[sum][n] = check_sum_mem(set, sum-set[n-1], n-1) || check_sum_mem(set, sum, n-1); 

	return dp[sum][n];
}

int main() {
	int n = 20;
	int set[20];
	for (int i = 0; i < 20; i++)
		set[i] = int(rand()%20);
	for (int i = 0; i < 20; i++)
		cout << set[i] << " ";
	cout << endl;
	int sum = 20;
	clock_t start = clock();
	cout << check_sum_mem(set, sum, 20) << endl;
	int t = clock() - start;
	cout << "Time taken is "<<1000*float(t)/CLOCKS_PER_SEC<<" ms"<<endl;
	return 0;
}