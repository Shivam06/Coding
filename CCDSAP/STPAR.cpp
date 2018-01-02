#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void check(vector<int> v, int n) {
	int end = n-1;
	stack<int> s;
	int count = 1, idx = end;
	while (idx >= 0) {
		if (v[idx] == count)
			count++;
		else {
			s.push(v[idx]);
		}
		idx--;
	}
	int tmp = s.top();
	s.pop();
	while (!s.empty()) {
		if (tmp <= s.top()) {
			tmp = s.top();
			s.pop();
		}
		else {
			cout <<"no"<<endl;
			return;
		}
	}
	cout << "yes" << endl;
}

int main() {
	int n, num;
	cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin>>num;
		v[n-i-1] = num;
	}
	check(v, n);
	return 0;
}