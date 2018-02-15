#include<iostream>
using namespace std;

void display(int ** cost, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
}

int min_cost(int**& cost, int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	if (i == 0 && j == 0)
		return cost[i][j];
	if (i + j <= 1) 
		return cost[i][j] + cost[0][0];

	return cost[i][j] + min(min_cost(cost, i-1, j), min(min_cost(cost, i-1, j-1), min_cost(cost, i, j-1)));
}

int min_cost_helper(int** cost, int i, int j, int**& min_c) {
	if (i < 0 || j < 0)
		return 0;
	if (i == 0 && j == 0)
		return cost[i][j];
	if (i+j <=1)
		return cost[i][j] + cost[0][0];	
	if (min_c[i][j])
		return min_c[i][j];
	else {
		min_c[i][j] = cost[i][j] + min(min_cost_helper(cost, i-1, j, min_c), min(min_cost_helper(cost, i-1, j-1, min_c), min_cost_helper(cost, i, j-1, min_c)));
		return min_c[i][j];
	}
}

int min_cost_mem(int** cost, int N, int i, int j) {
	int** min_c = new int*[N];
	for (int k = 0; k < N; k++) {
		min_c[k] = new int[N];
	}
	for (int k1 = 0; k1 < N; k1++) {
		for (int k2 = 0; k2 < N; k2++)
			min_c[k1][k2] = 0;
	}
	return min_cost_helper(cost, i, j, min_c);
}


int main() {
	int T, num, N;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>N;
		int** cost = new int*[N];
		for (int i = 0; i < N; i++) {
			cost[i] = new int[N];
		}
		for (int i = 0; i<N; i++) {
			for (int j = 0; j < N; j++) {
				cin>>num;
				cost[i][j] = num;
			}
		} 
		cout << min_cost_mem(cost, N, N-1, N-1) << endl;
	}
	return 0;
}