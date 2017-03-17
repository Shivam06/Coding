#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph {
private:
	int nodes;
	list<int>* G;
public:
	Graph(int n) {
		nodes = n;
		G = new list<int>[nodes];
	}
	void add_edge(int x, int y) {
		G[x].push_back(y);
	}
	void DFS(int s, int track_nodes[]) {
		if (track_nodes[s] == 1)
			return;
		cout << s << " ";
		track_nodes[s] = 1;
		if (G[s].size() == 0)
			return;
		for (list<int>::iterator itr = G[s].begin(); itr != G[s].end(); itr++) {
			if( track_nodes[*itr] == 1)
				continue;
			else {
				DFS(*itr, track_nodes);
			}
		}
	}
};

int main() {
	Graph Gph(4);
	Gph.add_edge(0,1);
	Gph.add_edge(0,2);
	Gph.add_edge(2,0);
	Gph.add_edge(2,3);
	Gph.add_edge(3,3);
	Gph.add_edge(1,2);
	int track_nodes[4] = {0};
	Gph.DFS(2, track_nodes);
	return 0;
}