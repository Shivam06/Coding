#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class greater_pair {
public:
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

int main() {
	int M = 3, N = 4;
	class greater_pair {
	public:
		bool operator() (pair<int, int> p1, pair<int, int> p2) {
			return p1.second > p2.second;
		}
	};
	vector<pair<int, int> > v{{{3,5},{1,2},{7,1}}};
	sort(v.begin(), v.end(), greater_pair());
	for (auto itr = v.begin(); itr != v.end(); itr++)
		cout << (*itr).first << " " << (*itr).second << endl;
	return 0;
}