#include<iostream>
#include<vector>
#include"graph.h"
using namespace std;

int main() {
	int nodes, edges;
	cin>>nodes>>edges;
	vector<int> adj[nodes+1];
	construct_adj_list(adj, nodes, edges, false);
	dfs(adj, nodes, 1);
	return 0;
}