#include<iostream>
using namespace std;

int main() {
	int nodes, edges;
	cin>>nodes>>edges;
	int adj_mat[nodes][nodes] = {};
	int x,y;
	for (int i = 0; i<edges; i++) {
		cin>>x>>y;
		adj_mat[x-1][y-1] = 1;
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++)
			cout << adj_mat[i][j] << " ";
		cout << endl;
	}

	return 0;
}