#include<iostream>
#include<list>
#include<queue>
using namespace std;

void BFS(list<int> G[], int nodes, int edges, int s) {
	queue<int> q;
	int track[nodes] = {0};
	q.push(s);

	while (!q.empty()) {
		int s = q.front();

		if (track[s] == 1) {
			q.pop();
			continue;
		}
		else {
			cout << s <<" ";
			track[s] = 1;
		}
		q.pop();

		if (G[s].size() == 0)
			continue;
		else {
			for (list<int> :: iterator itr = G[s].begin(); itr != G[s].end(); itr++) {
				if (track[*itr] == 0)
					q.push(*itr);
				else
					continue;
			}
		}
	}
}

int main() {
	int nodes, edges, x, y, S;
	cin>>nodes>>edges;

	list<int> Graph[nodes];
	for (int i = 0; i<edges; i++) {
		cin>>x>>y;
		Graph[x].push_back(y);
	}
	cout << "Enter the start node" << endl;
	cin>>S;
	BFS(Graph, nodes, edges, S);
	return 0;
}