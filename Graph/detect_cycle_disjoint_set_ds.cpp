// Detecting cycles in an undirected graph.

#include<iostream>
#include<utility>
#include<vector>
using namespace std;

// Graph having representation of array of edges. 
class Graph {
	int V;
	int E;
	vector<pair<int,int> >	edges;

public:
	Graph(int v, int e) {
		this->V = v;
		this->E = e;
	}

	void insert_edge(int u, int v) {
		edges.push_back(make_pair(u, v));
	}

	int detect_cycle();
};

int find(int s, int parent[]) {
	if (parent[s] == -1)
		return s;
	else
		return find(parent[s], parent);
}

void union_of_subset(int a, int b, int parent[]) {
	int parent_a = find(a, parent);
	int parent_b = find(b, parent);
	parent[parent_a] = parent_b;
}

int Graph::detect_cycle() {
	int parent[V];
	for (int i = 0; i < V; i++)
		parent[i] = -1;

	vector<pair<int, int> >::iterator itr;
	for (itr = edges.begin(); itr != edges.end(); itr++) {
		int x = (*itr).first;
		int y = (*itr).second;
		//cout << find(x,parent) << " " <<find(y, parent)<<endl;
		if (find(x, parent) == find(y, parent))
			return 1;
		union_of_subset(x, y, parent);
	}
	return 0;
}

int main() {
	Graph g(3, 3);
	g.insert_edge(0,1);
	g.insert_edge(1,2);
	g.insert_edge(0,2);
	cout << g.detect_cycle() << endl;
	return 0;
}