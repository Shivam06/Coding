#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
#define all(c) c.begin(), c.end()
#define tr(c, it) for(auto it = c.begin(); it != c.end(); it++)
#define present(c, v) (c.find(v) != c.end()) // Works for sets and maps (multi_sets, multi_maps, unordered_map)
#define cpresent(c, v) (find(all(c), v) != c.end()) // Works for vector, list.	


int main() {
	vi v{{1,5,2,6,9,5,2}};
	v.insert(v.begin(),8);
	cout << cpresent(v, 6) << endl;
	tr(v, it) {
		cout << *it << " ";
	}
	cout << endl;

	set<int> s(all(v));
	tr(s, it) 
		cout << *it << " ";
	cout << endl;

	if (cpresent(s, 9))
		cout << "Present" << endl;

	reverse(all(v));
	tr(v, it)
		cout << *it << " ";
	cout << endl;

	cout << "Minimum element is " << *min_element(all(v)) << endl;
	cout << "Maximum element is " << *max_element(all(v)) << endl;

	vi v3{{1,9,8}};
	sort(all(v3));

	do {
		tr(v3, it)
			cout << *it << " ";
		cout << endl; 
	}while(next_permutation(all(v3)));

	return 0;
}
