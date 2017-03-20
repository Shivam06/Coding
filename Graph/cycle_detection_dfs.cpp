// Cycle Detection for Directed Graph - O(V + E)

#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
	int V;
	list<int>* adj_li;

	public:
		Graph (int v) {
			this->V = v;
			adj_li = new list<int>[V];
		}

		void add_edge(int u, int v);
		int detect_cycle(int S);
		int detect_cycle_helper(int S, int track_nodes[], int stack_nodes[]);
};

void Graph::add_edge(int u, int v) {
	adj_li[u].push_back(v);
	return;
}

int Graph::detect_cycle_helper(int S, int track_nodes[], int stack_nodes[]) {
	

    if (stack_nodes[S] == 1)
    	return 1;
    if (track_nodes[S] == 1)
    	return 0;

    list<int> :: iterator i;
    stack_nodes[S] = 1;
    track_nodes[S] = 1;
    int a = 0;
    for (i = adj_li[S].begin(); i != adj_li[S].end(); i++) {
    	a += detect_cycle_helper(*i, track_nodes, stack_nodes);
    }
    stack_nodes[S] = 0;
    return a > 0;
}

int Graph::detect_cycle(int S) {
	int track_nodes[this->V] = {0};
    int stack_nodes[this->V] = {0};
    return detect_cycle_helper(S, track_nodes, stack_nodes);
}

int main() {
	Graph g(4);
	g.add_edge(3,0);
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(2,1);
	g.add_edge(1,3);
	cout << g.detect_cycle(0) << endl;
	return 0;
}