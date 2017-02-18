#include<iostream>
using namespace std;

int main()
{
	int edges, nodes;
	cin>>nodes>>edges;
	int adj_matrix[nodes][nodes] = {};
	int x, y;
	for (int i=0; i<edges; i++) {
		cin>>x>>y;
		adj_matrix[x-1][y-1] = 1;
		adj_matrix[y-1][x-1] = 1;
	}
	
	int q;
	cin>>q;
	for (int i = 0; i < q; i++){
		cin>>x>>y;
		if (adj_matrix[x-1][y-1] == 1)
			cout <<"YES"<<endl;
		else
			cout <<"NO"<<endl;
	}
	
	return 0;
}
