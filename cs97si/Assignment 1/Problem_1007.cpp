#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int merge_and_count(string str, int s, int m, int e) {
	int count = 0;
	int i =0, j = m+1, k = 0, n = m - s + 1;
	string str2;

	while ( i != m+1 && j != e+1 ) {
		if (str[i] <= str[j]) {
			str2[k] = str[i];
			i++;
		}
		else {
			str2[k] = str[j];
			count += n - i;
			j++;
		}
		k++;
	}

	if (i != m + 1) {
		for (;i<=m;i++)
			str2[k++] = str[i];
	}

	if (j != e + 1) {
		for (; j<=e; j++)
			str2[k++] = str[j];
	}

	for (int i = 0; i<e-s+1; i++)
		str[i] = str2[i];

	return count;
}

int merge_sort_and_count(string str, int s, int e) {
	if (s>=e)
		return 0;

	int m = (s + e)/2;

	int a = merge_sort_and_count(str, s, m);
	int b = merge_sort_and_count(str, m + 1, e);
	return a + b + merge_and_count(str, s, m, e);
}

int main() {
	int t, n, invs;
	cin>>n>>t;
	vector<pair<int, string> > v;
	string s;

	for (int i = 0; i<t; i++) {
		cin>>s;
		invs = merge_sort_and_count(s, 0, n);
		v.push_back(make_pair(invs, s));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i<t-1; i++)
		cout << v[i].second << endl;
	cout << v[t-1].second;
	return 0;
}