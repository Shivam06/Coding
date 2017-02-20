#include<iostream>
#include<vector>
#include "graph.h"
using namespace std;

void find_level_nodes(vector<int> adj[], int nodes, int x, int start_node = 1, int start_level = 1) {
	queue<int> nodeQ;
	int track_nodes[nodes + 1] = {0};
	int level_nodes[nodes + 1] = {0};
	track_nodes[0] = 1;
	int level = 1;
	level_nodes[level] = 1;
	track_nodes[start_node] = 1;
	nodeQ.push(start_node);
	while(!nodeQ.empty()) {
		int s = nodeQ.front();
		nodeQ.pop();
		level = level_nodes[s];
		if(level == x)
			cout << s << " ";
		if (!adj[s].size())
			continue;
		for (int i = 0; i < adj[s].size(); i++){
			if (!track_nodes[adj[s][i]]) {
				track_nodes[adj[s][i]] = 1;
				level_nodes[adj[s][i]] = level + 1;
				nodeQ.push(adj[s][i]);
			}
			else
				continue;
		}
	}
}

int main() {
	int nodes, edges;
	cout <<"Input number of nodes and edges"<<endl;
	cin>>nodes>>edges;
	vector<int> adj[nodes+1];
	construct_adj_list(adj, nodes, edges);
	display_graph(adj, nodes);
	cout << endl;
	find_level_nodes(adj, nodes, 3);
	return 0;
}