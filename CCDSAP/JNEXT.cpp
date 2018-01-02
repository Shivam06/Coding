#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

void display(vector<int>& v2) {
	for (int i = 0; i < v2.size();i++)
		cout<<v2[i]<<" ";
	cout << endl;
}

void find_next(vector<int>& v) {
	int end = v.size()-1;
	int i = end;
	while (i>0) {
		if (v[i] <= v[i-1]){
			i--;
			continue;
		}
		else {
			swap(v[i],v[i-1]);
			break;
		}
	}
	if (i>0) {
		sort(v.begin()+i, v.end());
		display(v);
	}
	else
		cout << -1 << endl;
}

int main() {
	vector<int> vec;
	int n, num;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>num;
		vec.push_back(num);
	}
	find_next(vec);
	//sort(vec.begin(), vec.end());
	//display(vec);
	return 0;
}