#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int> graph[], int nodes, int edges, int s) {
	static vector<int> tracked(nodes);
	if(tracked[s] == 1)
		return;
	cout << s << " ";
	tracked[s] = 1;
	for (int i = 0; i < graph[s].size(); i++) {
		dfs (graph, nodes, edges, graph[s][i]);
	}
	return;
}

int main() {
	int nodes, edges, x, y;
	cin>>nodes>>edges;
	vector<int> graph[nodes];

	for (int i = 0; i<edges; i++) {
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	dfs(graph, nodes, edges, 0);
	return 0;
}