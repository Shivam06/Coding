#include<iostream>
#include<vector>
using namespace std;

int count_vertices(vector<int> graph[], int n) {
	return n;
}

int count_edges(vector<int> graph[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		count += graph[i].size();
	}
	return count/2;
}

void degree(vector<int> graph[], int n) {
	vector<int> odd, even;

	for (int i = 0; i < n; i++) {
		if (graph[i].size()%2)
			odd.push_back(i);
		else
			even.push_back(i);	
	}

	cout << "There are " << even.size() << " number of even degree vertices" << endl;
	cout << "There are " << odd.size() << "number of odd degree vertices" << endl;
	cout << "Even degree vertices are :" << endl;
	for (int i = 0; i < even.size(); i++) {
		cout << even[i] << " ";
	}
	cout << endl;
	cout << "Odd degree vertices are :" << endl;
	for (int i = 0; i < odd.size(); i++) {
		cout << odd[i] << " ";
	} 
}

void insert_edge(vector<int> G[], int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

int main() {
	int n = 5;
	vector<int> graph[n];
	insert_edge(graph, 0, 1);
	insert_edge(graph, 0, 2);
	insert_edge(graph, 0, 3);
	insert_edge(graph, 1, 4);
	insert_edge(graph, 1, 2);
	insert_edge(graph, 3, 4);
	insert_edge(graph, 4, 2);

	cout << "Number of verties in graph are " << count_vertices(graph, n) << endl;
	cout << "Number of edges in graph are " << count_edges(graph, n) << endl;
	degree(graph, n);
	return 0;
}