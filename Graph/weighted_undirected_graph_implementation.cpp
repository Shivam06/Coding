#include<iostream>
#include"graph.h"
#include<vector>
using namespace std;


int main() {
	int nodes, edges;
	cin>>nodes>>edges;
	vector<pair<int, int>> G[nodes+1];
	int x,y,w;
	for (int i = 0; i<edges; i++) {
		cin>>x>>y>>w;
		G[x].push_back({y,w});
		G[y].push_back({x,w});
	}

	for (int i = 1; i <= nodes; i++) {
		cout << i << "--";
		int j = 0;
		if (G[i].size() == 0)
			continue;

		for (; j<G[i].size()-1; j++) {
			cout << "(" <<G[i][j].second <<")"<< "-->"<<G[i][j].first<<"--";
		}
		cout << "(" << G[i][j].second << ")" << "-->" << G[i][j].first<<endl;
	}
	return 0;
}