#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool find(vector<int> v, int a) {
	for (int i=0; i < v.size(); i++) {
		if(v[i] ==a)
			return true;
	}
	return false;
};

void construct_adj_list(vector<int> adj[], int nodes, int edges, bool isdirected = false) {
	int x,y;
	for(int i=0; i<edges; i++) {
		cin>>x>>y;
		if(!isdirected && !find(adj[y], x))
			adj[y].push_back(x);
		if (!find(adj[x],y))
			adj[x].push_back(y);
	}  // How to return vector array??
}

int find_level_nodes(vector<int> adj[], int nodes, int x, int start_node = 1, int start_level = 1) {
	queue<int> nodeQ;
	int* track_nodes = new int[nodes + 1];
	int* level_nodes = new int[nodes + 1];
	track_nodes[0] = 1;
	int level = 1;
	int count = 0;
	level_nodes[level] = 1;
	track_nodes[start_node] = 1;
	nodeQ.push(start_node);
	while(!nodeQ.empty()) {
		int s = nodeQ.front();
		nodeQ.pop();
		level = level_nodes[s];
		if(level == x) {
			count ++;
		}
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
	return count;
}

int main() {
	int nodes, edges, x;
	cin>>nodes;
	edges = nodes - 1;
	vector<int> adj[nodes+1];
	construct_adj_list(adj, nodes, edges);
	cin>>x;
	cout<<find_level_nodes(adj, nodes, x)<<endl;
	return 0;
}