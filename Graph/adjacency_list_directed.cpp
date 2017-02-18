#include<iostream>
#include<vector>
using namespace std;

int main() {
	int nodes, edges;
	cin>>nodes>>edges;
	vector<int> adj[nodes+1];
	int x,y;
	for (int i = 1; i <= edges; i++) {
		cin>>x>>y;
		adj[x].push_back(y);
	}

	for (int i = 1; i <= nodes; i++) {
		int j;
		cout<<i<<"-->";
		for (j = 0; j < adj[i].size()-1; j++)
			cout << adj[i][j] << "-->";
		cout << adj[i][j] << endl;
	}
	return 0;	
}