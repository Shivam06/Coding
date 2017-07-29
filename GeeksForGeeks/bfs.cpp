#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void bfs(list<int> graph[], int vertices, int s) {
	vector<int> visited(vertices);
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (auto i = graph[u].begin() ; i != graph[u].end(); i++) {
			int v = *i;	
			if (!visited[v]) {
				q.push(v);
				visited[v] = 1;
			}
		}
	}
}

int main() {
	int edges, vertices, x, y;
	cin>>vertices>>edges;
	list<int> graph[vertices];
	for (int i = 0; i < edges; i++) {
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(graph, vertices, 0);
}