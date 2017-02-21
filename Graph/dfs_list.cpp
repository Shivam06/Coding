#include<iostream>
#include<vector>
#include"graph.h"
using namespace std;

int main() {
	int nodes, edges;
	cin>>nodes>>edges;
	vector<int> adj[nodes+1];
	construct_adj_list(adj, nodes, edges, false);
	cout << "Enter Start Node" << endl;
	int start_node;
	cin>>start_node;
	cout << (nodes - dfs(adj, nodes, start_node)) << endl;
	return 0;
}