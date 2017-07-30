#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;
#define all(v) v.begin(), v.end()
#define loop(i, count) for(int i = 0; i < count; i++)
#define tr(c, it) for(auto it = c.begin(); it != c.end(); it++)

bool partition_helper(vi v, vi visited, int req, int sum) {
	if (sum == req)
		return true;
	if (sum > req)
		return false;

	loop(i, v.size()) {
		if (visited[i])
			continue;
		visited[i] = 1;
		sum += v[i];
		//cout << v[i] << " " << sum << endl;
		if (partition_helper(v, visited, req, sum))
			return true;
		sum -= v[i];
		visited[i] = 0;
	}

	return false;
}

bool partition(vi v) {
	int sum = 0;
	tr(v, it) {
		sum += *it;
	}	
	if (sum%2 != 0)
		return 0;

	vi visited(v.size());
	int cur = 0;
	int req = sum/2;
	return partition_helper(v, visited, req, cur);
}

int main() {
	int n = 6;
	vi v{{3, 5, 11, 5}};
	cout << partition(v) << endl;
	return 0;
}