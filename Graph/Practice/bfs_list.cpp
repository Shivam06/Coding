#include<iostream>
#include<list>
#include<queue>
using namespace std;

void bfs(list<int> graph[], int nodes, int edges, int s) {
	int track[nodes + 1] = {0};
	queue<int> q;
	q.push(s);
	track[s] = 1;
	while (!q.empty()) {
		int s = q.front();
		cout << s << " ";
		q.pop();
		for (auto itr = graph[s].begin(); itr!=graph[s].end(); itr++) {
			if (!track[*itr]) {
				q.push(*itr);
				track[*itr] = 1;
			}
			else
				continue;
		}
	}
}

int main() {
	int nodes, edges, x, y;
	cin>>nodes>>edges;
	list<int> graph[nodes+1];
	for (int i = 0; i<edges; i++) {
		cin>>x>>y;
		graph[x].push_back(y);
	}

	for (int i = 1; i <= nodes; i++) {
		cout << i;
		for (auto itr = graph[i].begin(); itr != graph[i].end(); itr++) {
			cout << "->" << *itr;
		}
		cout << endl;
	}

	bfs(graph, nodes, edges, 1);
	return 0;
}