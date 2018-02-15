#include<iostream>
#include<ctime>
#include<vector>
using namespace std;
#define R 3 
#define C 3

int min_cost(int cost[R][C], int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	if (i == 0 && j == 0)
		return cost[i][j];
	if (i + j <= 1) 
		return cost[i][j] + cost[0][0];

	return cost[i][j] + min(min_cost(cost, i-1, j), min(min_cost(cost, i-1, j-1), min_cost(cost, i, j-1)));
}

int min_cost_mem(int cost[R][C], int i, int j) {
	static int min_c[R][C] = {0};
	if (i < 0 || j < 0)
		return 0;
	if (i == 0 && j == 0)
		return cost[i][j];
	if (i+j <=1)
		return cost[i][j] + cost[0][0];
	if (min_c[i][j])
		return min_c[i][j];
	else {
		min_c[i][j] = cost[i][j] + min(min_cost_mem(cost, i-1, j), min(min_cost_mem(cost, i-1, j-1), min_cost_mem(cost, i, j-1)));
		return min_c[i][j];
	}
}

int main() {
	int cost[R][C] = {{1,2,8},
					  {4,8,2},
					  {1,5,3}};

	clock_t start = clock();
	cout << min_cost(cost, R-1, C-1) << endl;
	int t = clock()-start;
	cout << "Time in milliseconds is "<<1000*float(t)/CLOCKS_PER_SEC<<endl;
	start = clock();
	cout << min_cost_mem(cost, R-1, C-1) << endl;
	t = clock() - start;
	cout << "Time in milliseconds is "<<1000*float(t)/CLOCKS_PER_SEC<<endl;

	
	return 0; 
}