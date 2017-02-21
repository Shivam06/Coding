#include<iostream>
#include<vector>
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

void dfs_helper(vector<int> adj[], int nodes, int start_node, int track_nodes[]) {
	if (track_nodes[start_node] == 1)
		return;
	//cout << start_node << " ";
	track_nodes[start_node] = 1;
	for (int i = 0; i < adj[start_node].size(); i++) {
		dfs_helper(adj, nodes, adj[start_node][i], track_nodes);
	}
}

int dfs(vector<int> adj[], int nodes, int start_node) {
	int* track_nodes = new int[nodes+1];
	for (int i = 0; i<nodes + 1; i++)
		track_nodes[i] = 0;
	dfs_helper(adj, nodes, start_node, track_nodes);
	int sum = 0;
	for (int i = 0; i < nodes + 1; i++)
		sum += track_nodes[i];
	return sum;
}

int main()
{
    int nodes, edges, start_node;
    cin>>nodes>>edges;
    vector<int>* adj = new vector<int>[nodes+1];
    construct_adj_list(adj, nodes, edges);
    cin>>start_node;
    cout << nodes - dfs(adj, nodes, start_node) << endl;
    return 0;
}