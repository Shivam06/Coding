#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
#define INF 0x3f3f3f3f

vector<int> dijkstras(vector<pair<int,int> > graph[], int nodes, int edges, int s) {
	priority_queue<pair<int,int> > pq;
	vector<int> dist(nodes, INF);
	pq.push({0,s});
	dist[s] = 0;
	vector<int> visited(nodes);

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u] == 1)
			continue;
		visited[u] = 1;

		for (auto i = graph[u].begin(); i != graph[u].end(); i++) {
			int v = (*i).second;
			int w = (*i).first;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;	
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}

int main () {
	int nodes,edges,x,y,w;
	cin>>nodes>>edges;
	vector<pair<int, int> > graph[nodes];
	
	for (int i = 0; i < edges; i++) {
		cin>>x>>y>>w;
		graph[x].push_back(make_pair(w,y));
		graph[y].push_back(make_pair(w,x));
	}

	int s;
	cout << "Enter the source" << endl;
	cin>>s;

	vector<int> dist = dijkstras(graph, nodes, edges, s);

	for (int i = 0; i < nodes; i++)
		cout << s << "->" << i <<" : " << dist[i] << " ";
	return 0;
}