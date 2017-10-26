#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void display(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int max_water(vector<int>& pillars, int N) {
	//display(pillars);
	int total = 0;
	int i = 0;
	for (int j = i+1; j<N; j++) {
		if (pillars[j] >= pillars[i]) {
			//cout << pillars[j] << endl;
			int k = i+1;
			int val = min(pillars[i], pillars[j]);
			for (k; k < j; k++) {
				total = total + val - pillars[k];
			}
		}
	}
	//cout << total << endl;
	return total;
}

int order(vector<int> pillars, int N) {
	vector<int> best_order(N);
	int start = 0, end = N-1;

	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (i%2 == 0) {
			best_order[end--] = pillars[i];
		}
		else
			best_order[start++] = pillars[i];
	}

	//display(best_order);
	return max_water(best_order, N);
}

int main(){
	vector<int> pillars;
	int N, num;
	cin>>N;
	for(int i = 0; i < N; i++) { 
		cin>>num;
		pillars.push_back(num);
	}
	sort(pillars.begin(), pillars.end(), greater<int>());
	cout << order(pillars, N) << endl;
	return 0;
}