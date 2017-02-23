#include<iostream>
#include"graph.h"
#include<vector>
using namespace std;


int main() {
	int nodes, edges;
	cin>>nodes>>edges;
	vector<pair<int, int>> G[nodes];
	int x,y,w;
	for (int i = 0; i<edges; i++) {
		cin>>x>>y>>w;
		G[x].push_back({y,w});
	}

	for (int i = 0; i < nodes; i++) {
		cout << i << "-->";
		for (int j = 0; j<G[i].size()-1; j++) {
			cout << G[i][j].first << "("<<G[i][j].second<<")-->";
		}
		cout << G[i][j].first << "("<<G[i][j].second<<")"<<endl;
	}
	return 0;
}