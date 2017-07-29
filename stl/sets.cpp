#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	set<int> s{{3,6,1,2,5}};
	for (auto itr = s.begin(); itr != s.end(); itr++)
		cout << *itr << " ";
	cout << endl;
	s.insert(7);
	s.erase(1);
	for (auto itr = s.begin(); itr != s.end(); itr++)
		cout << *itr << " ";
	cout << endl;
	if (s.find(9) == s.end())
		cout << "Not Present" << endl;

	vector<int> v{{1,8,2,8,9,3}};
	set<int>s2(v.begin(), v.end());
	vector<int>v2(s2.begin(), s2.end());         // Vector with duplicates being removed.

	for (auto itr = v2.begin(); itr != v2.end(); itr++)
		cout << *itr << " ";        
	cout << endl;
	return 0;
}