#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define all(c) c.begin(), c.end()

int main() {	
	vector<int> v{{1,2,7,4}};
	cout << *lower_bound(all(v), 4) << endl;
	return 0;
}