#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std; 

void display(vector<int>& v2) {
	for (int i = 0; i < v2.size();i++)
		cout<<v2[i]<<" ";
	cout << endl;
}

void find_next(vector<int>& v) {
	int end = v.size()-1;
	int i = end;
	queue<int> q;
	while (i>0) {
		q.push(v[i]);
		if (v[i] <= v[i-1]){
			i--;
			continue;
		}
		else {
			int idx = end;
			while (q.front() <= v[i-1]) {
				//cout << "front " << q.front() << endl;
				q.pop();
				idx--;
			}
			swap(v[idx], v[i-1]);
			break;
		}
	}
	if (i>0) {
		reverse(v.begin()+i, v.end());
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
	return 0;
}