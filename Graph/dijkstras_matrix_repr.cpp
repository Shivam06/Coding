#include<iostream>
#include<climits>
#define V 9
using namespace std;


// Time complexity - O(V*E)
int shortest_distance(int dist[], int track_nodes[]) {
	// should return the index of the vertex with min distance from source and which hasn't been traced yet.
	int u, min = INT_MAX;
	for (int i = 0; i<V; i++) {
		if (dist[i] < min && !track_nodes[i]) {
			u = i;
			min = dist[i];
		}
	}
	return u;
}

void print_solution(int dist[]) {
	for (int i = 0; i < V; i++) {
		cout << "Vertex " << i << " : " << dist[i] << endl;
	}
}

void dijkstras(int graph[V][V], int S) {
	int track_nodes[V], dist[V]; // Declaring track_nodes[] and dist[] array for storing vertex which have been traced and 
	// to store distance of V from S resp.

	for (int i = 0; i<V; i++) {
		track_nodes[i] = 0; 
		dist[i] = INT_MAX;  // Initializing the 2 arrays
	}

	dist[S] = 0;   
	
	for (int i = 0; i < V-1; i++) {
		int u = shortest_distance(dist, track_nodes); // Finding the vertex which hasn't been traced yet and has min distance 
		// from source
		
		track_nodes[u] = 1; 

		for (int j = 0; j<V; j++) {
			if (graph[u][j]>0  && !track_nodes[j] && dist[u] + graph[u][j] <= dist[j]) {  // Updating the dist array by finding distance of neighbors of u from u
				dist[j] = dist[u] + graph[u][j];
			}
		}
	}
	print_solution(dist);
}

int main() {
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}};

  	dijkstras(graph, 0);
  	return 0;
}