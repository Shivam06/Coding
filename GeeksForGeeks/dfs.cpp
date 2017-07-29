#include<iostream>
#include<vector>
#include<list>
using namespace std;

typedef vector<int> vi;
#define all(c) c.begin(), c.end()
#define tr(c, it) for (auto it = c.begin(); it != c.end(); it++)

void dfs_helper(list<int> graph[], int vertices, int s, vi& visited) {
	//if (allVisited(visited))
	//	return;

	int u = s;

	tr(graph[u], it) {
		int v = *it;
		if (!visited[v]) {
			cout << v << " ";
			visited[v] = 1;
			dfs_helper(graph, vertices, v, visited);
		}
	}
}

void dfs(list<int> graph[], int vertices, int s) {
	vector<int> visited(vertices);
	visited[s] = 1;
	cout << s << " ";
	dfs_helper(graph, vertices, s, visited);
	cout << endl;
}

int main() {
	int edges, vertices, u, v;
	cin>>vertices>>edges;
	list<int> graph[vertices];

	for (int i = 0; i < edges; i++) {
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(graph, vertices, 0);
}
