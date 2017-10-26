#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	const char* name = "shivam";
	const char* name2 = "rahul";
	string s1(name);
	string s2(name2);
	unordered_map<char, int> m1, m2;

	for (int i = 0; i < s1.size(); i++) {
		m1[s1[i]] = 1;
	}

	if (m1['s'])
		cout << "true" << endl;

	for (int i = 0; i < s2.size(); i++) {
		m2[s2[i]] = 1;
	}

	if (m2['r'])
		cout << "true" << endl;

	for (auto it = s1.begin(); it != s1.end(); it++) {
		if (m2[*it]) {
			s1.erase(it);
			continue;
		}
	}
	
	for (auto it = s2.begin(); it != s2.end(); it++) {
		if (m1[*it]) {
			s2.erase(it);
			continue;
		}
	}

	cout << s1 + s2 << endl;
	cout << s1.append(s2, 1, 3) << endl;
	return 0;
}
