#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<climits>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(c) c.begin(), c.end()
#define tr(c, it) for(auto it = c.begin(); it != c.end(); it++)
#define present(c, v) (c.find(v) != c.end())
#define cpresent (find(all(c), v) != c.end())

void showPrim(vi dist, vi parent) {
	for (int i = 0; i < parent.size(); i++) {
		cout << parent[i] << " -> " << i << endl; 
	}
}
void prim(list<ii> graph[], int vertices) {
	int source = 0;
	vi visited(vertices);
	//visited[s] = 1;
	set<ii> s;
	vi dist(vertices, INT_MAX);
	vi parent(vertices);
	parent[source] = -1;
	dist[source] = 0;
	s.insert({dist[source], 0});

	while (!s.empty()) {
		int u = (*s.begin()).second;
		cout << u << endl;
		visited[u] = 1;
		s.erase(s.begin());

		tr(graph[u], it) {
			int v = (*it).second;

			if (visited[v])
				continue;

			int w = (*it).first;
			if (w < dist[v]) {
				int temp = dist[v];
				dist[v] = w;
				parent[v] = u;
				if (present(s, make_pair(temp, v))) {
					s.erase({temp, v});
				}
				s.insert({dist[v], v});
			}
		}
	}
	showPrim(dist, parent);
}

int main() {
	int edges, vertices, u, v, w;
	cin>>vertices>>edges;
	list<ii> graph[vertices];
	for (int i = 0; i < edges; i++) {
		cin>>u>>v>>w;
		graph[u].push_back({w,v});
		graph[v].push_back({w,u});
	}
	prim(graph, vertices);
	return 0;
}