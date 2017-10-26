#include<iostream>
using namespace std;

string isLucky(int pages[], int cost[], int size, int K, int N) {
	for (int i = 0; i < N; i++) {
		if (cost[i] <= K && size <= pages[i])
			return "LuckyChef";
	}
	return "UnluckyChef";
} 

int main() {
	int T, X, Y, K, N;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>X>>Y>>K>>N;
		int size = X-Y;
		int pages[N], cost[N];
		for (int i = 0; i < N; i++) {
			cin>>pages[i]>>cost[i];
		}
		cout << isLucky(pages, cost, size, K, N) << endl; 
	}
	return 0;
}