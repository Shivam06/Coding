#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph_union(vvi& G1, int n1, vvi& G2, int n2) {
	int n = max(n1, n2);
	vvi G = G2;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			G[i][j] = G[i][j] + G1[i][j];
			if (G[i][j] > 0)
				G[i][j] = 1;
		}
	}
	return G;
}

vvi graph_intersection(vvi& G1, int n1, vvi& G2, int n2) {
	int n = max(n1, n2);
	vvi G(n2, vi(n2,0));
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			G[i][j] = G1[i][j] - G2[i][j];
			if (G[i][j] == 0)
				G[i][j] = G1[i][j];
			else
				G[i][j] = 0;
		}
	}
	return G;
}

vvi graph_ring_sum(vvi& G1, int n1, vvi& G2, int n2) {
	vvi GI = graph_intersection(G1, n1, G2, n2);
	vvi GU = graph_union(G1, n1, G2, n2);
	vvi GR = GU;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n2; j++) 
			GR[i][j] = GR[i][j] - GI[i][j];
	}
	return GR;
}

void display_graph(vvi& G, int n, string name) {
	cout << "Matrix representation of " << name << " is" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << G[i][j] << "\t";
		}
		cout << endl;
	}
}

void insert_edge(vvi & G, int u, int v) {
	G[u][v] = 1;
	G[v][u] = 1;
}

int main() {
	int n1 = 3, n2 = 5;
	vector<vector<int> > G1(n1, vector<int>(n1));
	vector<vector<int> > G2(n2, vector<int>(n2));
	insert_edge(G1, 0, 1);
	insert_edge(G1, 1, 2);
	insert_edge(G1, 0, 2);

	insert_edge(G2, 0, 2);
	insert_edge(G2, 0, 4);
	insert_edge(G2, 1, 2);
	insert_edge(G2, 1, 3);
	insert_edge(G2, 2, 3);
	insert_edge(G2, 2, 4);

	display_graph(G1, n1, "G1");
	cout << endl;
	display_graph(G2, n2, "G2");
	cout << endl;

	vvi GU = graph_union(G1, n1, G2, n2);
	display_graph(GU, GU.size(), "Union of G1 and G2");

	vvi GI = graph_intersection(G1, n1, G2, n2);
	display_graph(GI, GI.size(), "Intersection of G1 and G2");

	vvi GR = graph_ring_sum(G1, n1, G2, n2);
	display_graph(GR, GR.size(), "Ring sum of G1 and G2");
	return 0;
}