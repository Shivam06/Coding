#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int T,x,y,M;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>M>>x>>y;
		int diff = x*y;
		int arr[M];
		for (int j = 0; j < M; j++) 
			cin>>arr[j];
		sort(arr, arr + M);
		int safe = 0, min = 1;
		for (int j = 0; j < M; j++) {
			safe += (arr[j]-diff > min? arr[j]-diff-min: 0);
			min = arr[j] + diff + 1;
		}
		safe += (100 - min + 1>0?100-min+1:0);
		cout << safe << endl;
	}
}