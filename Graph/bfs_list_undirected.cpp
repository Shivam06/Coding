#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool find(vector<int> v, int a) {
	for (int i=0; i < v.size(); i++) {
		if(v[i] ==a)
			return true;
	}
	return false;
}

void construct_adj_list(vector<int> adj[], int nodes, int edges, bool isdirected = false) {
	int x,y;
	cout << "Input start and end node" << endl;
	for(int i=0; i<edges; i++) {
		cin>>x>>y;
		if(!isdirected && !find(adj[y], x))
			adj[y].push_back(x);
		if (!find(adj[x],y))
			adj[x].push_back(y);
	}  // How to return vector array??
}

void display_graph(vector<int> adj[], int nodes) {
	for (int i=1; i<=nodes; i++) {
		cout <<i<<"-->";
		int j;
		if(!adj[i].size())
			continue;
		for (j = 0; j<adj[i].size()-1; j++) 
			cout << adj[i][j] <<"-->";
		cout << adj[i][j] <<endl;
	}
}

void bfs(vector<int> adj[], int nodes, int start_node) {
	queue<int> nodeQ;
	int track_nodes[nodes + 1] = {0};
	track_nodes[0] = 1;
	
	int level = 0;
	cout << start_node<<" ";
	track_nodes[start_node] = 1;
	nodeQ.push(start_node);
	while(!nodeQ.empty()) {
		int s = nodeQ.front();
		nodeQ.pop();
		if (!adj[s].size())
			continue;
		level++;
		for (int i = 0; i < adj[s].size(); i++){
			if (!track_nodes[adj[s][i]]) {
				track_nodes[adj[s][i]] = 1;
				cout << adj[s][i] <<" ";
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
	bfs(adj, nodes, 1);
	return 0;
}