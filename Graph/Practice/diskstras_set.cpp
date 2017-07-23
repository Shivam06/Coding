#include<iostream>
#include<set>
#include<vector>
#include<list>
using namespace std;
#define INF 0x3f3f3f3f

vector<int> shortest_path(list<pair<int, int> > graph[], int nodes, int edges, int s) {
	set<pair<int, int> > min_heap;
	vector<int> dist(nodes, INF);
	dist[s] = 0;
	min_heap.insert(make_pair(0, s));

	while (!min_heap.empty()) {
		int u = (*(min_heap.begin())).second;
		min_heap.erase(min_heap.begin());

		for (auto i = graph[u].begin(); i != graph[u].end(); i++) {
			int w = (*i).first;
			int v = (*i).second;
			if (dist[v] > dist[u] + w) {
				if (dist[v] != INF) {
					min_heap.erase(min_heap.find(make_pair(dist[v], v)));
				}
				dist[v] = dist[u] + w;
				min_heap.insert(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main() {
	int nodes, edges, x, y, w;
	cin>>nodes>>edges;
	list<pair<int, int> > graph[nodes];
	for (int i = 0; i<edges; i++) {
		cin>>x>>y>>w;
		graph[x].push_back(make_pair(w,y));
		graph[y].push_back(make_pair(w,x));
	}

	int s = 0;
	vector<int> dist = shortest_path(graph, nodes, edges, s);
	for (int i = 0; i < dist.size(); i++) {
		cout << s << "->" << i << " : " << dist[i] << endl;
	}
	return 0;
}

