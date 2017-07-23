#include<iostream>
#include<list>
#include"graph.h"
using namespace std;



int detect_cycle_util(list<int> graph[], int s, vector<int> visited, vector<int> rec_stack) {

	if (rec_stack[s] == 1)
		return 1;
	if (visited[s] == 1)
		return 0;
	visited[s] = 1;
	rec_stack[s] = 1;
	int sum = 0;
	for (auto itr = graph[s].begin(); itr != graph[s].end(); itr++) {
		sum += detect_cycle_util(graph, *itr, visited, rec_stack);
	}
	rec_stack[s] = 0;
	return sum > 0;
}

int detect_cycle(list<int> graph[], int nodes, int edges) {
	vector<int> visited(nodes);
	vector<int> rec_stack(nodes);
	int s = 0;
	return detect_cycle_util(graph, s, visited, rec_stack);
}

int main() {
	int nodes, edges, x, y;
	cin>>nodes>>edges;
	list<int> graph[nodes];
	for (int i = 0; i < edges; i++) {
		cin>>x>>y;
		graph[x].push_back(y);
	}

	int s = 0;
	cout << detect_cycle(graph, nodes, edges) << endl;
	return 0;
}